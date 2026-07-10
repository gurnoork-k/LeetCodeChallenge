import os
import re

REPO_ROOT = "."
README_PATH = "README.md"

# Folders to ignore
IGNORE = {".git", ".github", "scripts", "node_modules"}

def get_problem_folders():
    folders = []
    for name in os.listdir(REPO_ROOT):
        if os.path.isdir(name) and name not in IGNORE and re.match(r"^\d{4}-", name):
            folders.append(name)
    return sorted(folders, key=lambda x: int(x.split("-")[0]))

def folder_to_title(folder):
    # "0017-letter-combinations-of-a-phone-number" -> "Letter Combinations Of A Phone Number"
    parts = folder.split("-")[1:]
    return " ".join(p.capitalize() for p in parts)

def build_table(folders):
    rows = ["| # | Problem | Folder |", "|---|---------|--------|"]
    for folder in folders:
        num = str(int(folder.split("-")[0]))
        title = folder_to_title(folder)
        rows.append(f"| {num} | {title} | [{folder}](./{folder}) |")
    return "\n".join(rows)

def update_readme(table):
    with open(README_PATH, "r") as f:
        content = f.read()

    start_marker = "<!-- PROBLEMS_TABLE_START -->"
    end_marker = "<!-- PROBLEMS_TABLE_END -->"

    new_section = f"{start_marker}\n{table}\n{end_marker}"

    if start_marker in content and end_marker in content:
        content = re.sub(
            f"{start_marker}.*?{end_marker}",
            new_section,
            content,
            flags=re.DOTALL
        )
    else:
        content += f"\n\n## ✅ Solved\n{new_section}\n"

    with open(README_PATH, "w") as f:
        f.write(content)

if __name__ == "__main__":
    folders = get_problem_folders()
    table = build_table(folders)
    update_readme(table)
    print(f"Updated README with {len(folders)} problems.")