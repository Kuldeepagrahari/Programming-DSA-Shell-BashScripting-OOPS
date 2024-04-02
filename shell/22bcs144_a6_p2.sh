#!/bin/bash

# Check if source and destination files are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 source_file destination_file"
    exit 1
fi

source_file="$1"
destination_file="$2"

# Check if source file exists
if [ ! -f "$source_file" ]; then
    echo "Error: Source file '$source_file' does not exist."
    exit 1
fi

# Ensure destination directory exists
destination_dir=$(dirname "$destination_file")
if [ ! -d "$destination_dir" ]; then
    mkdir -p "$destination_dir"
fi

# Attempt to acquire a lock on the destination file
while [ -f "$destination_file.lock" ]; do
    sleep 0.1
done
touch "$destination_file.lock"

# Copy the file
cp "$source_file" "$destination_file"

# Remove the lock file
rm -f "$destination_file.lock"

echo "Successfully copied file: $source_file to $destination_file"
