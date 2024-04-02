#!/bin/bash

# Loop to create 10 empty files
for ((i=1; i<=10; i++)); do
    touch "file${i}.txt"
done

echo "Files created successfully."
