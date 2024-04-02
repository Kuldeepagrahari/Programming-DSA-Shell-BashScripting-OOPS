#!/bin/bash

# Initialize counter
counter=0

# Function for updating counter
update_counter() {
    counter=$((counter+10000))
}
update_counter
# Creating child processes
update_counter & process1_pid=$!
update_counter & process2_pid=$!

# Wait for child processes to finish
wait $process1_pid
wait $process2_pid

# Display final counter value
echo "Final counter value: $counter"
