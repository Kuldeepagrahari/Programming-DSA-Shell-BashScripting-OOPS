#!/bin/bash

# Function to allocate memory to blocks as per Best fit algorithm
bestFit() {
    local blockSize=("${!1}")
    local processSize=("${!2}")
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
        # Find the best fit block for current process
        local bestIdx=-1
        for ((j = 0; j < m; j++)); do
            if ((${blockSize[$j]} >= ${processSize[$i]})); then
                if ((bestIdx == -1)); then
                    bestIdx=$j
                elif ((${blockSize[$bestIdx]} > ${blockSize[$j]})); then
                    bestIdx=$j
                fi
            fi
        done

        # If we could find a block for current process
        if ((bestIdx != -1)); then
            # allocate block j to p[i] process
            allocation[$i]=$bestIdx

            # Reduce available memory in this block.
            blockSize[$bestIdx]=$((blockSize[$bestIdx] - ${processSize[$i]}))
        fi
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
processSize=(212 417 112 426)
m=${#blockSize[@]}
n=${#processSize[@]}

bestFit blockSize[@] processSize[@] $m $n
