#!/bin/bash

# Check if lock exists
if [ -f copy.lock ]; then
    echo "Another process is copying a file. Please try again later."
    exit 1
fi

# Create lock file
touch copy.lock

# Copy the file
cp "$1" "$2" && echo "Successfully copied file: $1 to $2"

# Remove lock file
rm copy.lock
