#!/bin/bash

# Loop through all files with .jpg extension
for file in *.jpg; do
    # Check if file exists
    if [ -e "$file" ]; then
        # Rename file to .png
        mv "$file" "${file%.jpg}.png"
    fi
done

echo "Renaming completed."
