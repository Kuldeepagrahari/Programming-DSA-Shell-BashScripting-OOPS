capitalize_first() {
    input_string=$1
    capitalized_string=$(echo "$input_string" | awk '{for(i=1;i<=NF;i++) $i=toupper(substr($i,1,1)) tolower(substr($i,2))} 1')
    echo "$capitalized_string"
}

print_char_freq() {
    input_string=$1
    echo "$input_string" | grep -o . | sort | uniq -c
}

# Example usage:
input="hello world example"
capitalized=$(capitalize_first "$input")
echo "Capitalized string: $capitalized"

echo "Character frequency count:"
print_char_freq "$capitalized"
