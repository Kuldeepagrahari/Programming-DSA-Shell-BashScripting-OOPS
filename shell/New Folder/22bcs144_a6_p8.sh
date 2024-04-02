#!/bin/bash

# Function for summing numbers
sum_numbers() {
    local sum=0
    while IFS= read -r num; do
        ((sum += num))
    done < "$1"
    echo "$sum"
}

# Main script
sum=$(sum_numbers numbers.txt)
echo "The sum of all numbers is: $sum"
