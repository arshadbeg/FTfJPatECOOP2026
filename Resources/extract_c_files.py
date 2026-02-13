import os
import re
import html
from bs4 import BeautifulSoup

def get_function_name(c_code):
    match = re.search(r'\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\([^)]*\)\s*\{', c_code)
    if match:
        return match.group(1)
    return None

def sanitize_filename(name):
    return re.sub(r'[^a-zA-Z0-9_]', '_', name)

def extract_c_files_from_html(html_file):
    if not os.path.exists(html_file):
        print(f"{html_file} not found in the current directory.")
        return
    
    with open(html_file, 'r', encoding='utf-8') as f:
        soup = BeautifulSoup(f, 'html.parser')
    
    # Get all text content
    text_content = soup.get_text(separator="\n")
    
    # Decode HTML entities
    text_content = html.unescape(text_content)
    
    # Split text into blocks based on multiple newlines
    blocks = [block.strip() for block in text_content.split("\n\n") if block.strip()]
    
    c_file_count = 0
    for i, block in enumerate(blocks, start=1):
        if re.search(r'\b(int|return|#include|void|char)\b', block):
            func_name = get_function_name(block)
            if func_name:
                filename = sanitize_filename(func_name) + ".c"
            else:
                filename = f"extracted_{i}.c"
            
            # Avoid overwriting existing files
            counter = 1
            orig_filename = filename
            while os.path.exists(filename):
                filename = f"{orig_filename[:-2]}_{counter}.c"
                counter += 1
            
            with open(filename, 'w', encoding='utf-8') as c_file:
                c_file.write(block)
            
            print(f"Extracted C code to {filename}")
            c_file_count += 1
    
    if c_file_count == 0:
        print("No C code found in the HTML file.")

if __name__ == "__main__":
    extract_c_files_from_html("index.html")

