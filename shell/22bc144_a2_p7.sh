#!/bin/bash
read -p "email: " email
# Check for the presence of "@" and "."
if [[ $email == *'@'* && $email == *'.'* ]]; then
    echo "Valid"
else
    echo "Invalid"
fi

