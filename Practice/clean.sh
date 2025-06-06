#!/bin/bash

# Find and delete all a.out files in the current directory and subdirectories
find . -type f -name "a.out" -exec rm -v {} \;

echo "All a.out files deleted successfully."

