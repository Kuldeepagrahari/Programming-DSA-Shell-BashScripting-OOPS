#!/bin/bash
echo "Enter a number: "
read num
sqrt_int=$(echo "sqrt($num)" | bc)
if [ $(($sqrt_int * $sqrt_int)) -eq $num ]; then
    echo "$num is a perfect square."
else
    echo "$num is not a perfect square."
fi

