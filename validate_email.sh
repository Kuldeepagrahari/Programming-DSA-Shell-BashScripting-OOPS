#!/bin/bash

# Function to validate email address
validate_email() {
    email=$1
    if [[ $email =~ ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$ ]]; then
        echo "Valid email address"
    else
        echo "Invalid email address"
    fi
}

# Main script
echo "Enter an email address:"
read input_email
validate_email "$input_email"
