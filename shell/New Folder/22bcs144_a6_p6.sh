#!/bin/bash

# Function for downloading file
download_file() {
    url="$1"
    filename=$(basename "$url")
    echo "Downloading file: $url"
    curl -sS "$url" -o "$filename" && echo "Downloaded file: $url to $filename"
}

# Read URLs from file and download concurrently
while IFS= read -r url; do
    download_file "$url" &
done < file_list.txt

# Wait for all downloads to finish
wait
