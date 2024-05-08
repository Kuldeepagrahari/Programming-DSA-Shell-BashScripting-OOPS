#!/bin/bash

# Define the disk size and initial head position
disk_size=200
initial_head_position=100

# Define an array of disk requests
requests=(150 50 175 125 25)


c_look() {
    current_head_position=$initial_head_position
    total_head_movement=0

    for ((i=0; i<${#requests[@]}; i++)); do
        if ((requests[$i] >= current_head_position)); then
            break
        fi
    done

    for ((j=i; j<${#requests[@]}; j++)); do
        ((total_head_movement += requests[$j] - current_head_position))
        current_head_position=${requests[$j]}
    done

    for ((j=0; j<i; j++)); do
        ((total_head_movement += current_head_position - requests[$j]))
        current_head_position=${requests[$j]}
    done

    echo "C-LOOK Total Head Movement: $total_head_movement"
}



c_look


