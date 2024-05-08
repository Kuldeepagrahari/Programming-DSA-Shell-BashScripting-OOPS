#!/bin/bash

# Define the disk size and initial head position
disk_size=200
initial_head_position=50

# Define an array of disk requests
requests=(30 70 90 120 170)

# FCFS
fcfs() {
    current_head_position=$initial_head_position
    total_head_movement=0

    for request in "${requests[@]}"; do
        ((total_head_movement += (request > current_head_position ? request - current_head_position : current_head_position - request)))
        current_head_position=$request
    done

    echo "FCFS Total Head Movement: $total_head_movement"
}

# SCAN
# SCAN
scan() {
    current_head_position=$initial_head_position
    x=$initial_head_position
    total_head_movement=0

    for ((i=0; i<${#requests[@]}; i++)); do
        if ((requests[$i] >= current_head_position)); then
           ((total_head_movement += requests[$i] - current_head_position))
           current_head_position=${requests[$i]}
        fi
    done
    ((total_head_movement += 200 - current_head_position))
    current_head_position=200

    for ((j=4; j>=0; j--)); do
    if ((requests[$j] < x)); then
        ((total_head_movement += current_head_position - requests[$j]))
        current_head_position=${requests[$j]}
    fi
    done

    echo "SCAN Total Head Movement: $total_head_movement"
}


# C-SCAN
c_scan() {
    current_head_position=$initial_head_position
    x=$initial_head_position
    total_head_movement=0

   for ((i=0; i<${#requests[@]}; i++)); do
        if ((requests[$i] >= current_head_position)); then
           ((total_head_movement += requests[$i] - current_head_position))
           current_head_position=${requests[$i]}
        fi
    done

    ((total_head_movement += 200 - current_head_position+200))
    current_head_position=0

    for ((j=4; j>=0; j--)); do
    if ((requests[$j] < x)); then
        ((total_head_movement += requests[$j]-current_head_position ))
        current_head_position=${requests[$j]}
    fi
    done

    echo "C-SCAN Total Head Movement: $total_head_movement"
}

# LOOK
look() {
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

    for ((j=i-1; j>=0; j--)); do
        ((total_head_movement += current_head_position - requests[$j]))
        current_head_position=${requests[$j]}
    done

    echo "LOOK Total Head Movement: $total_head_movement"
}

# C-LOOK
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

# shortest SEEK time algo
seek() {
    current_head_position=$initial_head_position
    total_head_movement=0

    for request in "${requests[@]}"; do
        ((total_head_movement += (request > current_head_position ? request - current_head_position : current_head_position - request)))
        current_head_position=$request
    done

    echo "SEEK Total Head Movement: $total_head_movement"
}

# Run the algorithms
fcfs
scan
c_scan
look
c_look
seek

