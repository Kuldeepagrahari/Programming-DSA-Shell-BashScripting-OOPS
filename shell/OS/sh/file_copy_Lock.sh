#!/bin/bash

LOCK_FILE="/tmp/copy_lock"
exec 200>"$LOCK_FILE"

flock -n 200 || { echo "Another process is copying a file. Exiting..."; exit 1; }

cp "$1" "$2"

flock -u 200

echo "File copied successfully from $1 to $2"
