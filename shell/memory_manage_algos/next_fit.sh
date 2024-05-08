#!/bin/bash

# Function to allocate memory to blocks as per Next fit algorithm
NextFit() {
    local -a blockSize=("${!1}")
    local -a processSize=("${!2}")
    local m=$3
    local n=$4

    # Stores block id of the block allocated to a process
    local -a allocation
    local j=0
    local t=$((m - 1))

    # pick each process and find suitable blocks
    # according to its size and assign to it
    for ((i = 0; i < n; i++)); do

        # Do not start from beginning
        while ((j < m)); do
            if ((${blockSize[$j]} >= ${processSize[$i]})); then

                # allocate block j to p[i] process
                allocation[$i]=$j

                # Reduce available memory in this block.
                blockSize[$j]=$((blockSize[$j] - ${processSize[$i]}))

                # sets a new end point
                t=$(( (j - 1) % m ))
                break
            fi
            if ((t == j)); then
                # sets a new end point
                t=$(( (j - 1) % m ))
                # breaks the loop after going through all memory block
                break
            fi

            # mod m will help in traversing the
            # blocks from starting block after
            # we reach the end.
            j=$(( (j + 1) % m ))
        done
    done

    echo -e "\nProcess No.\tProcess Size\tBlock no.\n"
    for ((i = 0; i < n; i++)); do
        echo -n " $((i + 1))" $'\t\t'"${processSize[$i]}" $'\t\t'
        if ((${allocation[$i]} != -1)); then
            echo $((allocation[$i] + 1))
        else
            echo "Not Allocated"
        fi
        echo -e "\n"
    done
}

# Main driver code
blockSize=(5 10 20)
processSize=(10 20 4)
m=${#blockSize[@]}
n=${#processSize[@]}

NextFit blockSize[@] processSize[@] $m $n
