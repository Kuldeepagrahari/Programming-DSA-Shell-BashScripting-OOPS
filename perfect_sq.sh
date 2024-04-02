#!/bin/bash

# Function to check if a number is a perfect square
is_perfect_square() {
    num=$1
    square_root=$(echo "sqrt($num)" | bc)
    if [ $((square_root * square_root)) -eq $num ]; then
        echo "The number is a perfect square"
    else
        echo "The number is not a perfect square"
    fi
}

# Main script
echo "Enter a number:"
read number

is_perfect_square "$number"
