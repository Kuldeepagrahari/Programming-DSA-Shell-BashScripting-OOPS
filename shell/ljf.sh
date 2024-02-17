#!/bin/bash

# Define a function to execute a job
execute_job() {
    job_id=$1
    burst_time=$2
    sleep $burst_time
    end_time=$(date +%s)
    echo "Job $job_id finished at time $end_time"
}

# Array of process IDs, arrival times, and burst times
processes=(
    "P1 0 3"
    "P2 1 2"
    "P3 2 4"
    "P4 3 5"
    "P5 4 6"
)

# Sort processes based on burst time in descending order
sorted_processes=($(printf '%s\n' "${processes[@]}" | sort -k3 -n -r))

# Initialize total waiting time and total turnaround time
total_waiting_time=0
total_turnaround_time=0

# Execute processes in descending order of burst time (Longest Job First)
for process in "${sorted_processes[@]}"
do
    read -r -a process_info <<< "$process"
    process_id=${process_info[0]}
    arrival_time=${process_info[1]}
    burst_time=${process_info[2]}
    
    # Wait for arrival time if needed
    current_time=$(date +%s)
    if [ $current_time -lt $arrival_time ]; then
        sleep $((arrival_time - current_time))
    fi
    
    # Execute the job
    execute_job $process_id $burst_time &
    
    # Update total waiting time and total turnaround time
    waiting_time=$((current_time - arrival_time))
    total_waiting_time=$((total_waiting_time + waiting_time))
    total_turnaround_time=$((total_turnaround_time + waiting_time + burst_time))
done

# Wait for all jobs to finish
wait

# Calculate average waiting time and average turnaround time
num_processes=${#sorted_processes[@]}
average_waiting_time=$(bc <<< "scale=2; $total_waiting_time / $num_processes")
average_turnaround_time=$(bc <<< "scale=2; $total_turnaround_time / $num_processes")

# Print results
echo "Average waiting time: $average_waiting_time"
echo "Average turnaround time: $average_turnaround_time"
