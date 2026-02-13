import os
import re

INPUT_DIR = "clean_c_files"
OUTPUT_DIR = "acsl_augmented_c_files"

os.makedirs(OUTPUT_DIR, exist_ok=True)

# Regex patterns
FUNC_RE = re.compile(
    r"([a-zA-Z_][\w\s\*]*)\s+([a-zA-Z_]\w*)\s*\(([^)]*)\)\s*\{",
    re.MULTILINE
)
IF_RE = re.compile(r"if\s*\(([^)]+)\)", re.MULTILINE)
ELSE_RE = re.compile(r"else", re.MULTILINE)
LOOP_RE = re.compile(r"(for|while|do)\s*\(([^)]*)\)", re.MULTILINE)
SWITCH_RE = re.compile(r"switch\s*\(([^)]+)\)\s*\{", re.MULTILINE)
CASE_RE = re.compile(r"case\s+([^:]+):|default\s*:", re.MULTILINE)
MAIN_RE = re.compile(r"int\s+main\s*\(\s*\)\s*\{", re.MULTILINE)
ASSIGN_CALL_RE = re.compile(r"(\w+)\s*=\s*(\w+)\s*\(([^)]*)\)\s*;", re.MULTILINE)

# Helper functions
def extract_body(code, start):
    depth = 0
    i = start
    while i < len(code):
        if code[i] == "{":
            depth += 1
        elif code[i] == "}":
            depth -= 1
            if depth == 0:
                return code[start:i+1]
        i += 1
    return ""

def parse_params(param_str):
    params = {}
    if param_str.strip() == "" or param_str.strip() == "void":
        return params
    for p in param_str.split(","):
        p = p.strip()
        name = p.split()[-1].replace("*","")
        params[name] = {
            "raw": p,
            "is_ptr": "*" in p,
            "read": False,
            "written": False
        }
    return params

def sanitize_condition(cond_str):
    if not cond_str:
        return "\\true"
    cond_str = cond_str.strip()
    while cond_str.startswith("(") and cond_str.endswith(")"):
        inner = cond_str[1:-1].strip()
        depth = 0
        balanced = True
        for ch in inner:
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth < 0:
                    balanced = False
                    break
        if balanced and depth == 0:
            cond_str = inner
        else:
            break
    cond_str = " ".join(cond_str.split())
    return cond_str

def analyze_body_for_return(body, params):
    if_match = IF_RE.search(body)
    else_match = ELSE_RE.search(body)
    if not if_match:
        return None, None, None

    cond_raw = if_match.group(1)
    cond_str = sanitize_condition(cond_raw)

    body_after_if = body[if_match.end():]
    ret_if_match = re.search(r"return\s+([^;]+);", body_after_if)
    if not ret_if_match:
        return None, None, None
    return_if = ret_if_match.group(1).strip()

    if else_match:
        body_after_else = body[else_match.end():]
        ret_else_match = re.search(r"return\s+([^;]+);", body_after_else)
        return_else = ret_else_match.group(1).strip() if ret_else_match else None
    else:
        return_else = None

    return cond_str, return_if, return_else

def generate_implication_acsl(cond_str, return_if, return_else):
    acsl = "/*@\n"
    acsl += f"  ensures ({cond_str}) ==> \\result=={return_if};\n"
    if return_else:
        acsl += f"  ensures !({cond_str}) ==> \\result=={return_else};\n"
    acsl += "*/\n"
    return acsl

def generate_loop_acsl(loop_code):
    """
    Detects loop variable, array accessed, and size variable for ACSL.
    Generates Gemini-style loop annotations for array loops.
    """
    # Detect loop variable: e.g., for(int j=0; j<n-1; j++)
    loop_var_match = re.search(r"for\s*\(\s*int\s+(\w+)\s*=", loop_code)
    loop_var = loop_var_match.group(1) if loop_var_match else "i"

    # Detect array variable: look for pattern arr[index]
    array_vars = list(set(re.findall(r"([a-zA-Z_]\w*)\s*\[", loop_code)))

    # Detect size variable: look for pattern < n
    n_var_match = re.search(rf"{loop_var}\s*<\s*([a-zA-Z_]\w*)", loop_code)
    n_var = n_var_match.group(1) if n_var_match else None

    acsl = "/*@\n"
    # Precondition
    if n_var:
        acsl += f"\trequires {n_var}>0;\n"
    for arr in array_vars:
        if n_var:
            acsl += f"\trequires \\valid({arr}+ (0..{n_var}-1));\n"

    # Loop invariants
    acsl += f"\tloop invariant 0<={loop_var}<={n_var}-1;\n"
    for arr in array_vars:
        acsl += f"\tloop invariant \\forall integer i; 0<=i<{loop_var} ==> {arr}[{loop_var}] >= {arr}[i];\n"

    # Loop assigns
    assigns_clause = f"{loop_var}, " + ", ".join([f"{arr}[0..{loop_var}+1]" for arr in array_vars])
    acsl += f"\tloop assigns {assigns_clause};\n"

    # Loop variant
    if n_var:
        acsl += f"\tloop variant {n_var}-1-{loop_var};\n"
    acsl += "*/\n"

    return acsl

def process_main(code):
    m = MAIN_RE.search(code)
    if not m:
        return code  # no main found

    # Find starting brace
    brace_pos = code.find("{", m.end()-1)
    if brace_pos == -1:
        print("Warning: main() has no opening brace. Skipping main processing.")
        return code

    body_start = brace_pos + 1
    depth = 1
    i = body_start
    body_end = None
    while i < len(code):
        if code[i] == "{":
            depth += 1
        elif code[i] == "}":
            depth -= 1
            if depth == 0:
                body_end = i
                break
        i += 1

    if body_end is None:
        print("Warning: Could not find the closing brace of main(). Skipping main processing.")
        return code

    main_body = code[body_start:body_end]

    # Insert assertions after each assignment call
    new_body = ""
    last_pos = 0
    for assign_match in ASSIGN_CALL_RE.finditer(main_body):
        start, end = assign_match.span()
        var_name = assign_match.group(1)
        args = assign_match.group(3)

        new_body += main_body[last_pos:end]

        # Determine assertion
        arg_literal = args.strip()
        if arg_literal.startswith("'") or arg_literal.isdigit():
            if arg_literal in ("' '","'\\0'","0"):
                new_body += f"\n\t//@ assert !{var_name} ;\n"
            else:
                new_body += f"\n\t//@ assert {var_name}==1 ;\n"
        else:
            new_body += f"\n\t//@ assert {var_name} ;\n"

        last_pos = end

    new_body += main_body[last_pos:]
    code = code[:body_start] + new_body + code[body_end:]
    return code

# Main processing
for fname in os.listdir(INPUT_DIR):
    if not fname.endswith(".c"):
        continue

    with open(os.path.join(INPUT_DIR, fname), "r", encoding="utf-8", errors="ignore") as f:
        code = f.read()

    inserts = []

    for m in FUNC_RE.finditer(code):
        ret_type, func_name, params_str = m.groups()
        if func_name.strip().replace("*","").lower() == "main":
            continue

        body_start = m.end()-1
        body = extract_body(code, body_start)
        params = parse_params(params_str)

        cond_str, ret_if, ret_else = analyze_body_for_return(body, params)
        if cond_str:
            acsl = generate_implication_acsl(cond_str, ret_if, ret_else)
            inserts.append((m.start(), acsl))

        # Loops
        for loop_match in LOOP_RE.finditer(body):
            loop_pos = body_start + loop_match.start()
            loop_cond = loop_match.group(2)
            loop_acsl = generate_loop_acsl(loop_cond)
            inserts.append((loop_pos, loop_acsl))

        # Switch / case
        for switch_match in SWITCH_RE.finditer(body):
            switch_start = switch_match.end()
            switch_body = extract_body(body, switch_start-1)
            for case_match in CASE_RE.finditer(switch_body):
                case_cond = case_match.group(1) if case_match.group(1) else None
                case_code_start = case_match.end()
                case_code = switch_body[case_code_start:]
                returns = re.findall(r"return\s+([^;]+);", case_code)
                if returns:
                    acsl = "/*@\n"
                    for r in returns:
                        if case_cond:
                            acsl += f"  ensures ({case_cond}) ==> \\result=={r.strip()};\n"
                        else:
                            acsl += f"  ensures \\result=={r.strip()};\n"
                    acsl += "*/\n"
                    case_pos = body_start + switch_start + case_match.start()
                    inserts.append((case_pos, acsl))

    # Insert ACSL
    inserts.sort(key=lambda x: x[0])
    offset = 0
    for pos, acsl in inserts:
        code = code[:pos+offset] + acsl + code[pos+offset:]
        offset += len(acsl)

    # Process main for assertions
    code = process_main(code)

    with open(os.path.join(OUTPUT_DIR, fname), "w", encoding="utf-8") as f:
        f.write(code)

print("ACSL generation completed.")

