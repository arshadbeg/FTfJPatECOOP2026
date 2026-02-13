import os
import re

INPUT_DIR = "input_c_files"
OUTPUT_DIR = "clean_c_files"

os.makedirs(OUTPUT_DIR, exist_ok=True)

# Regex patterns for ACSL
acsl_block = re.compile(r"/\*@.*?\*/", re.DOTALL)
acsl_line = re.compile(r"//@.*?$", re.MULTILINE)

processed = 0

for filename in os.listdir(INPUT_DIR):
    if not filename.endswith(".c"):
        continue

    input_path = os.path.join(INPUT_DIR, filename)
    output_path = os.path.join(OUTPUT_DIR, filename)

    with open(input_path, "r", encoding="utf-8", errors="ignore") as f:
        code = f.read()

    # Remove ACSL annotations
    code = re.sub(acsl_block, "", code)
    code = re.sub(acsl_line, "", code)

    with open(output_path, "w", encoding="utf-8") as f:
        f.write(code)

    processed += 1

print(f"Processed {processed} files.")

