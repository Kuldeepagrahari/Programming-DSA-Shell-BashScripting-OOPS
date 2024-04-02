count() {
    string="$1"
    length=${#string}
    num_vowels=$(echo "$string" | tr -cd 'aeiouAEIOU' | wc -c)
    
    echo "Length of the string: $length"
    echo "Number of vowels: $num_vowels"
}

# Example usage:
count "Hello, World!"
