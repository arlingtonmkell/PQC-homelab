#!/bin/bash

# Output file
OUTPUT_FILE="wrapper-snapshot.txt"
MAX_SIZE=51200  # Max size in bytes (50 KB)
INCLUDE_EXTENSIONS=("sh" "py" "js" "ts" "jsx" "tsx" "html" "css" "json" "md" "txt")

# Clear output file
echo "🔁 Generating recursive snapshot..." > "$OUTPUT_FILE"

# Check if file extension is allowed
is_allowed_extension() {
  local ext="${1##*.}"
  for allowed in "${INCLUDE_EXTENSIONS[@]}"; do
    if [[ "$ext" == "$allowed" ]]; then
      return 0
    fi
  done
  return 1
}

# Function to scan and log files
scan_directory() {
  local dir="$1"
  for file in "$dir"/*; do
    # Skip hidden files and folders
    [[ "$(basename "$file")" = .* ]] && continue
    [[ "$file" == *"node_modules"* || "$file" == *".git"* ]] && continue

    if [ -f "$file" ]; then
      size=$(stat -c%s "$file")
      if is_allowed_extension "$file" && [ "$size" -le "$MAX_SIZE" ]; then
        echo "===== FILE: $file =====" >> "$OUTPUT_FILE"
        cat "$file" >> "$OUTPUT_FILE"
        echo -e "\n" >> "$OUTPUT_FILE"
      fi
    elif [ -d "$file" ]; then
      scan_directory "$file"
    fi
  done
}

# Start scan
scan_directory .

echo "✅ Snapshot complete. Output saved to $OUTPUT_FILE"
