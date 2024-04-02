#!/bin/bash

# Function to check if two strings are anagrams
check_anagram() {
    str1=$1
    str2=$2
    if [ $(echo "$str1" | tr -d ' ' | tr '[:upper:]' '[:lower:]' | grep -o . | sort | tr -d '\n') = \
         $(echo "$str2" | tr -d ' ' | tr '[:upper:]' '[:lower:]' | grep -o . | sort | tr -d '\n') ]; then
        echo "Anagrams"
    else
        echo "Not Anagrams"
    fi
}

# Main script
echo "Enter the first string:"
read str1
echo "Enter the second string:"
read str2

check_anagram "$str1" "$str2"
