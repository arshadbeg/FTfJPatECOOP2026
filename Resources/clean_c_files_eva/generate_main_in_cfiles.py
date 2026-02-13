import os
import re

# Always operate in script directory
FOLDER = os.path.dirname(os.path.abspath(__file__))

FUNC_DEF_RE = re.compile(
    r'^\s*(?!static\b)([a-zA-Z_][\w\s\*\d]*?)\s+([a-zA-Z_]\w*)\s*\(([^)]*)\)\s*\{',
    re.MULTILINE
)

# Matches a full main() function body (simple & safe)
MAIN_FUNC_RE = re.compile(
    r'\bint\s+main\s*\([^)]*\)\s*\{.*?\n\}',
    re.DOTALL
)


def is_array(param):
    return "[" in param and "]" in param


def is_pointer(param):
    return "*" in param and not is_array(param)


def parse_array(param):
    base, rest = param.split("[", 1)
    size = rest.split("]")[0].strip()
    size = size if size.isdigit() else "1"

    parts = base.strip().rsplit(" ", 1)
    if len(parts) == 2:
        return parts[0], parts[1], size
    return parts[0], "arr", size


def parse_pointer(param):
    parts = param.replace("*", " * ").split()
    base_type = " ".join(parts[:-2])
    name = parts[-1]
    return base_type.strip(), name


def default_scalar_value(param_type):
    t = param_type.strip()
    if "float" in t or "double" in t:
        return "0.0"
    if "char" in t:
        return "'A'"
    return "0"


def parse_parameters(param_str):
    if not param_str or param_str.strip() == "void":
        return []
    return [p.strip() for p in param_str.split(",")]


def generate_main(func_name, params):
    declarations = []
    args = []

    for p in params:
        if is_array(p):
            base_type, name, size = parse_array(p)
            var = f"{name}_var"
            init = ", ".join(["0"] * int(size))
            declarations.append(
                f"{base_type} {var}[{size}] = {{{init}}};"
            )
            args.append(var)

        elif is_pointer(p):
            base_type, name = parse_pointer(p)
            var = f"{name}_var"
            init = default_scalar_value(base_type)
            declarations.append(
                f"{base_type} {var} = {init};"
            )
            args.append(f"&{var}")

        else:
            p_type = p.rsplit(" ", 1)[0]
            args.append(default_scalar_value(p_type))

    decls = "\n    ".join(declarations)
    call = f"{func_name}({', '.join(args)});"

    return f"""

int main(void)
{{
    {decls}
    {call}
    return 0;
}}
"""


def process_c_file(path):
    print(f"Fixing: {os.path.basename(path)}")

    with open(path, "r", encoding="utf-8") as f:
        content = f.read()

    # Remove existing main() if present
    content = MAIN_FUNC_RE.sub("", content).rstrip()

    functions = FUNC_DEF_RE.findall(content)
    if not functions:
        print("  No suitable function found, skipping")
        return

    _, func_name, params = functions[0]
    param_list = parse_parameters(params)
    main_code = generate_main(func_name, param_list)

    with open(path, "w", encoding="utf-8") as f:
        f.write(content + main_code)


def main():
    for file in os.listdir(FOLDER):
        if file.endswith(".c"):
            process_c_file(os.path.join(FOLDER, file))


if __name__ == "__main__":
    main()

