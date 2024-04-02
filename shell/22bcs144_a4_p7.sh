print() {
    size=$1

    for ((i = 1; i <= size; i++)); do
        for ((j = 1; j <= i; j++)); do
            echo -n "*"
        done
        echo ""
    done
}

# Example usage:
print 5
