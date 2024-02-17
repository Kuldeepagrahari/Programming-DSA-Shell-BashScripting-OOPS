#!/bin/bash

# Define an associative array to store the burst times for each process
declare -A burst_times=( [0]=2 [1]=4 [2]=8 )

# Function to calculate the turnaround time for each process
calculate_turnaround_time() {
    local completion_time=$1
    local turnaround_time
    for pid in "${!burst_times[@]}"; do
        turnaround_time=$((completion_time - arrival_time[pid]))
        echo "Turnaround time for Process $pid: $turnaround_time"
        total_turnaround_time=$((total_turnaround_time + turnaround_time))
    done
}

# Main LRTF scheduling logic
arrival_time=([0]=0 [1]=0 [2]=0)
total_turnaround_time=0
current_time=0

while true; do
    remaining_time=0
    selected_pid=-1

    # Select the process with the longest remaining time
    for pid in "${!burst_times[@]}"; do
        if (( burst_times[pid] > remaining_time )); then
            remaining_time=${burst_times[pid]}
            selected_pid=$pid
        elif (( burst_times[pid] == remaining_time && pid < selected_pid )); then
            # If remaining time is the same, break ties by selecting the process with the lowest PID
            selected_pid=$pid
        fi
    done

    # Check if all processes have completed
    if (( remaining_time == 0 )); then
        echo "All processes have completed execution."
        break
    fi

    # Execute the selected process
    echo "Process $selected_pid is executing at time $current_time"
    sleep $remaining_time
    current_time=$((current_time + remaining_time))

    # Update the burst time and arrival time of the selected process
    unset burst_times[$selected_pid]

    # Calculate the turnaround time for the completed process
    calculate_turnaround_time $current_time
done

# Calculate the average turnaround time
num_processes=${#arrival_time[@]}
average_turnaround_time=$(bc << "scale=2; $total_turnaround_time / $num_processes")
echo "Average Turnaround Time: $average_turnaround_time units"
