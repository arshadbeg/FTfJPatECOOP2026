import os
import re

INPUT_DIR = "input_c_files"
OUTPUT_DIR = "clean_c_files_updated"

os.makedirs(OUTPUT_DIR, exist_ok=True)

# ACSL patterns
acsl_block = re.compile(r"/\*@.*?\*/", re.DOTALL)
acsl_line = re.compile(r"//@.*?$", re.MULTILINE)

# C comments
c_block_comment = re.compile(r"/\*.*?\*/", re.DOTALL)
c_line_comment = re.compile(r"//.*?$", re.MULTILINE)

# Very conservative function matcher
function_pattern = re.compile(
    r"""
    (?P<signature>
        [\w\s\*\(\),]+
    )
    \{
        (?P<body>
            (?:[^{}]|\{[^{}]*\})*
        )
    \}
    """,
    re.DOTALL | re.MULTILINE | re.VERBOSE
)

processed = 0

for filename in os.listdir(INPUT_DIR):
    if not filename.endswith(".c"):
        continue

    input_path = os.path.join(INPUT_DIR, filename)
    output_path = os.path.join(OUTPUT_DIR, filename)

    with open(input_path, "r", encoding="utf-8", errors="ignore") as f:
        code = f.read()

    preserved_functions = []

    def handle_function(match):
        signature = match.group("signature")
        body = match.group("body")

        # Remove ACSL and comments to test emptiness
        test_body = acsl_block.sub("", body)
        test_body = acsl_line.sub("", test_body)
        test_body = c_block_comment.sub("", test_body)
        test_body = c_line_comment.sub("", test_body)

        if test_body.strip() == "":
            # Empty function → preserve EXACTLY as-is
            token = f"__PRESERVE_FUNC_{len(preserved_functions)}__"
            preserved_functions.append(match.group(0))
            return token

        # Non-empty function → strip ACSL inside
        cleaned_body = acsl_block.sub("", body)
        cleaned_body = acsl_line.sub("", cleaned_body)
        return signature + "{" + cleaned_body + "}"

    # 1. Process functions
    code = re.sub(function_pattern, handle_function, code)

    # 2. Remove ACSL outside functions
    code = acsl_block.sub("", code)
    code = acsl_line.sub("", code)

    # 3. Restore preserved empty functions
    for i, func in enumerate(preserved_functions):
        code = code.replace(f"__PRESERVE_FUNC_{i}__", func)

    with open(output_path, "w", encoding="utf-8") as f:
        f.write(code)

    processed += 1

print(f"Processed {processed} files.")

