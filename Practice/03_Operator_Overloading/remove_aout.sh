#! /bin/bash

# Loop through all directories in the current directory
for d in */; do
    # Remove trailing slash
    d="${d%/}"

    # Split into number and rest by first underscore
    number="${d%%_*}"
    rest="${d#*_}"

    # Strip leading zeros
    number=$((10#$number))

    # Format back to two-digit with leading zero if needed
    newnumber=$(printf "%02d" "$number")

    # Construct new directory name
    newname="${newnumber}_${rest}"

    # Rename
    mv "$d" "$newname"

    echo "Renamed $d to $newname"

done

