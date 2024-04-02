#!/bin/bash

# Function for process 1
process1() {
    for ((i = 1; i <= 10; i += 2)); do
        echo "Process 1: $i"
        sleep 1
    done
}

# Function for process 2
process2() {
    for ((i = 2; i <= 10; i += 2)); do
        echo "Process 2: $i"
        sleep 1
    done
}

# Creating child processes
process1 & process1_pid=$!
process2 & process2_pid=$!

# Wait for child processes to finish
wait $process1_pid
wait $process2_pid
