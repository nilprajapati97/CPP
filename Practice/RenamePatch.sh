#!/bin/bash

# Find all .md files in subdirectories and rename them to .patch
find . -type f -name "*.md" | while read -r file; do
    new_file="${file%.md}.patch"
    mv "$file" "$new_file"
    echo "Renamed: $file -> $new_file"
done

