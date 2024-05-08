#!/bin/bash

# Simulate a queue of disk requests
disk_queue=(150 50 175 125 25)
initial_head_position=100 # Initial position of the disk head

echo "Disk queue: ${disk_queue[@]}"

# Simulate disk scheduling using C-LOOK algorithm and calculate total head movement
echo "Servicing disk requests using C-LOOK algorithm:"
total_head_movement=0
current_head_position=$initial_head_position

# Sort the disk queue to facilitate the C-LOOK algorithm
sorted_disk_queue=($(printf '%s\n' "${disk_queue[@]}" | sort -n))

# Find the index of the initial head position in the sorted disk queue
head_index=0
for ((i=0; i<${#sorted_disk_queue[@]}; i++)); do
    if [ ${sorted_disk_queue[$i]} -ge $initial_head_position ]; then
        head_index=$i
        break
    fi
done

# Service requests in the forward direction until the end of the disk
for ((i=head_index; i<${#sorted_disk_queue[@]}; i++)); do
    request=${sorted_disk_queue[$i]}
    echo "Servicing request for disk sector $request"
    # Calculate head movement for the current request
    head_movement=$(($request - $current_head_position))
    if [ $head_movement -lt 0 ]; then
        head_movement=$((-$head_movement))
    fi
    total_head_movement=$(($total_head_movement + $head_movement))
    current_head_position=$request
    # Simulate disk access time
    sleep 1
done

# Wrap around to the beginning of the disk and continue servicing requests in the forward direction
if [ $head_index -gt 0 ]; then
    echo "Wrapping around to the beginning of the disk"
    # Service requests from the beginning of the sorted disk queue up to the head_index
    for ((i=0; i<head_index; i++)); do
        request=${sorted_disk_queue[$i]}
        echo "Servicing request for disk sector $request"
        # Calculate head movement for the current request
        head_movement=$(($request - $current_head_position))
        if [ $head_movement -lt 0 ]; then
            head_movement=$((-$head_movement))
        fi
        total_head_movement=$(($total_head_movement + $head_movement))
        current_head_position=$request
        # Simulate disk access time
        sleep 1
    done
fi

echo "Total head movement: $total_head_movement"
 
