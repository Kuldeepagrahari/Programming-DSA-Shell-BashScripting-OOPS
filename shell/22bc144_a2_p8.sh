#!/bin/bash
read -p "first " str1
read -p "second " str2
clean_str1=$(echo "$str1" | tr -d ' ' | tr '[:upper:]' '[:lower:]')
clean_str2=$(echo "$str2" | tr -d ' ' | tr '[:upper:]' '[:lower:]')
sorted_str1=$(echo "$clean_str1" | grep -o . | sort | tr -d '\n')
sorted_str2=$(echo "$clean_str2" | grep -o . | sort | tr -d '\n')
if [ "$sorted_str1" == "$sorted_str2" ]; then
    echo "The strings are anagrams."
else
    echo "The strings are not anagrams."
fi

