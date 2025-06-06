#!/bin/bash

# Find and delete all a.out files from current directory and subdirectories
find . -type f -name "a.out" -exec rm -f {} \;

echo "All a.out files removed."

