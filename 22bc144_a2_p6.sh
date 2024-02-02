#!/bin/bash
read -p "Enter a string: " input_string
if [[ $input_string =~ [[:lower:]] && $input_string =~ [[:upper:]] ]]; then
    echo "Yes"
else
    echo "No"
fi

