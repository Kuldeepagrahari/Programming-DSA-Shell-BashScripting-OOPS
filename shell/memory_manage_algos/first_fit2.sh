#!/bin/bash

# Function to allocate memory to blocks as per First fit algorithm
firstFit() {
    local -a blockSize=("${!1}")
    local -a processSize=("${!2}")
    local m=$3
    local n=$4

    # Stores block id of the block allocated to a process
    local -a allocation

    # Initially no block is assigned to any process
    for ((i = 0; i < n; i++)); do
        allocation[$i]=-1
    done

    # pick each process and find suitable blocks
    # according to its size and assign to it
    for ((i = 0; i < n; i++)); do
        for ((j = 0; j < m; j++)); do
            if ((blockSize[$j] >= processSize[$i])); then
                # allocate block j to p[i] process
                allocation[$i]=$j

                # Reduce available memory in this block.
                blockSize[$j]=$((blockSize[$j] - processSize[$i]))

                break
            fi
        done
    done

    echo -e "\nProcess No.\tProcess Size\tBlock no."
    for ((i = 0; i < n; i++)); do
        echo -n " $((i + 1))" $'\t\t'"${processSize[$i]}" $'\t\t'
        if ((${allocation[$i]} != -1)); then
            echo $((allocation[$i] + 1))
        else
            echo "Not Allocated"
        fi
    done
}

# Main driver code
blockSize=(100 500 200 300 600)
processSize=(212 417 12 300)
m=${#blockSize[@]}
n=${#processSize[@]}

firstFit "blockSize[@]" "processSize[@]" $m $n
