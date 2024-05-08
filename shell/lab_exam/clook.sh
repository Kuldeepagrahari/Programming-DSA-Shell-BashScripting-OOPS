#!/bin/bash

# Function to calculate total head movements
calculate_head_movements() {
    local head_movements=0
    local current_head=$1
    shift
    for request in "$@"; do
        local distance=$((request - current_head))
        if [ $distance -lt 0 ]; then
            distance=$((distance * -1))
        fi
        head_movements=$((head_movements + distance))
        current_head=$request
    done
    echo $head_movements
}

# Function to sort the disk requests
sort_disk_requests() {
    IFS=$'\n' sorted=($(sort -n <<<"${1[*]}"))
    echo "${sorted[*]}"
}

# Function to simulate C-LOOK disk scheduling algorithm
c_look() {
    local current_head=$1
    local prev_head=$2
    shift 2
    local requests=("$@")

    local sorted_requests=$(sort_disk_requests "${requests[*]}")

    local service_order=()
    local head_movements=0

    # Find the index of current head position in sorted requests
    local index=0
    for ((i=0; i<${#sorted_requests[@]}; i++)); do
        if [ ${sorted_requests[$i]} -ge $current_head ]; then
            index=$i
            break
        fi
    done

    # Service requests in one direction
    for ((i=index; i<${#sorted_requests[@]}; i++)); do
        service_order+=(${sorted_requests[$i]})
        current_head=${sorted_requests[$i]}
    done

    # For C-LOOK, head moves directly to the beginning of the disk
    for ((i=0; i<index; i++)); do
        service_order+=(${sorted_requests[$i]})
        current_head=${sorted_requests[$i]}
    done

    head_movements=$(calculate_head_movements $prev_head ${service_order[@]})
    echo "Service Order: ${service_order[*]}"
    echo "Total Head Movements: $head_movements"
}

# Input
prev_head_position=90
current_head_position=100
disk_requests=(150 50 175 125 25)

# Output
c_look $current_head_position $prev_head_position "${disk_requests[@]}"
