#!/bin/bash

download_file() {
    local url="$1"
    local filename=$(basename "$url")
    
    wget -q "$url" -O "$filename"
    
    if [ $? -eq 0 ]; then
        echo "Downloaded: $filename"
    else
        echo "Failed to download: $filename"
    fi
}

download_files() {
    local urls_file="$1"
    local lock_file="$2"
    
    > "$lock_file"
    
    while IFS= read -r url || [[ -n "$url" ]]; do
        (
            # Acquire a lock before downloading the file
            flock -x 200
            
            # Download the file
            download_file "$url"
            
            # Release the lock
            flock -u 200
        ) 200>"$lock_file" &
    done < "$urls_file"
    
    wait
}

if [ $# -ne 2 ]; then
    echo "Usage: $0 <urls_file> <lock_file>"
    exit 1
fi

urls_file="$1"
lock_file="$2"

download_files "$urls_file" "$lock_file"

