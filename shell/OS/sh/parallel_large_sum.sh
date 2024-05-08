#!/bin/bash

# Function to calculate the sum of a list of numbers
calculate_sum() {
    local start=$1
    local end=$2
    local sum=0

    for ((i = start; i <= end; i++)); do
        read -r num
        sum=$((sum + num))
    done

    echo "$sum"
}

# Get the total number of lines in the file
total_lines=$(wc -l < numbers.txt)

# Specify the number of child processes
num_processes=4

# Calculate the number of lines each process will handle
lines_per_process=$((total_lines / num_processes))

# Initialize variables
start_line=1
end_line=$lines_per_process

# Create an array to store process IDs
pids=()

# Loop to create child processes
for ((i = 1; i <= num_processes; i++)); do
    # Spawn a child process and pass the start and end line numbers
    calculate_sum "$start_line" "$end_line" | {
        # Read the sum from the child process
        read -r sum
        echo "Process $i sum: $sum"

        # Store the sum in a temporary file to avoid race conditions
        echo "$sum" >> sum_temp.txt

        # Notify the parent process that this child has completed
        echo "Process $i completed" >&2
    } &

    # Store the process ID
    pids+=($!)

    # Update start and end line numbers for the next process
    start_line=$((end_line + 1))
    end_line=$((end_line + lines_per_process))
done

# Wait for all child processes to complete
for pid in "${pids[@]}"; do
    wait "$pid"
done

# Calculate the final sum by adding all partial sums
final_sum=$(awk '{sum+=$1} END{print sum}' sum_temp.txt)

# Clean up temporary files
rm sum_temp.txt

echo "Final sum: $final_sum"

