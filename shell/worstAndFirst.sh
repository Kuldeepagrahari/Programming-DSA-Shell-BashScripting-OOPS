#!/bin/bash

first_fit() {
    local process_name=$1
    local process_size=$2
    local num_blocks=$3
    local block_size=("${@:4}")

    for ((i=0; i<num_blocks; i++)); do
        if [ ${block_status[$i]} -eq 0 ] && [ ${block_size[$i]} -ge $process_size ]; then
            block_status[$i]=1
            echo "Process $process_name allocated to block $i"
            return
        fi
    done

    echo "Process $process_name cannot be allocated"
}


worst_fit() {
    local process_name=$1
    local process_size=$2
    local num_blocks=$3
    local block_size=("${@:4}")

    local worst_index=-1
    local worst_size=0

    for ((i=0; i<num_blocks; i++)); do
        if [ ${block_status[$i]} -eq 0 ] && [ ${block_size[$i]} -ge $process_size ]; then
            if [ ${block_size[$i]} -gt $worst_size ]; then
                worst_index=$i
                worst_size=${block_size[$i]}
            fi
        fi
    done

    if [ $worst_index -ne -1 ]; then
        block_status[$worst_index]=1
        echo "Process $process_name allocated to block $worst_index"
    else
        echo "Process $process_name cannot be allocated"
    fi
}

# Main code
echo "Enter the number of memory blocks:"
read num_blocks

# Initialize memory blocks as free
for ((i=0; i<num_blocks; i++)); do
    echo "Enter size of block $i:"
    read block_size[$i]
    block_status[$i]=0
done

echo "Enter the number of processes:"
read num_processes

# Allocate memory to processes
for ((i=0; i<num_processes; i++)); do
    echo "Enter name of process $i and its size:"
    read process_name process_size

    echo "Using First Fit algorithm:"
    first_fit "$process_name" "$process_size" "$num_blocks" "${block_size[@]}"

    echo "Using Worst Fit algorithm:"
    worst_fit "$process_name" "$process_size" "$num_blocks" "${block_size[@]}"
done
