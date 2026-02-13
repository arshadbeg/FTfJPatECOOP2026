#!/usr/bin/env python3

"""
Remove non-C diagnostic text inserted at the beginning of Frama-C generated files.

Specifically removes lines such as:
  [kernel] Warning: ...
  [kernel] Parsing ...
  [rte:annot] annotating ...

Keeps content starting from the first valid C line (e.g. #include, typedef, struct, or code).

Usage:
  python clean_rte_headers.py            # cleans all .c files in current directory
  python clean_rte_headers.py file1.c    # cleans specific files
"""

import sys
import re
from pathlib import Path

# Regex for Frama-C / kernel / rte diagnostic lines
DIAG_PATTERN = re.compile(r"^\[(kernel|rte:annot|wp|eva|from|slicing).*\]")

# Heuristic: valid C usually starts with one of these
C_START_PATTERN = re.compile(r"^\s*(#include|#define|typedef|struct|enum|union|extern|static|void|int|char|float|double|long|short|signed|unsigned|_Bool|/\*|//)")


def clean_file(path: Path):
    lines = path.read_text(errors="ignore").splitlines(keepends=True)

    cleaned = []
    started = False

    for line in lines:
        if not started:
            # Skip diagnostic lines
            if DIAG_PATTERN.match(line):
                continue
            # Detect start of real C code
            if C_START_PATTERN.match(line):
                started = True
                cleaned.append(line)
        else:
            cleaned.append(line)

    # Overwrite file only if something remains
    if cleaned:
        path.write_text("".join(cleaned))


def main():
    # If no arguments are given, process all .c files in current directory
    if len(sys.argv) == 1:
        files = sorted(Path('.').glob('*.c'))
    else:
        files = [Path(f) for f in sys.argv[1:]]

    if not files:
        print("No .c files found.")
        return

    for path in files:
        if path.is_file() and path.suffix == '.c':
            clean_file(path)
        else:
            print(f"Skipping non-C file: {path}")


if __name__ == "__main__":
    main()

