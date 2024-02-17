#!/bin/bash

# Define a function to execute a job
execute_job() {
    job_id=$1
    burst_time=$2
    sleep $burst_time
    end_time=$(date +%s)
    echo "Job $job_id finished at time $end_time"
}

# Array of process IDs and burst times
processes=(
    "0 2"
    "1 4"
    "2 8"
)

# Sort processes based on burst time in descending order
sorted_processes=($(printf '%s\n' "${processes[@]}" | sort -k2 -n -r))

# Initialize total turnaround time
total_turnaround_time=0

# Execute processes in descending order of burst time (Longest Remaining Time First)
for process in "${sorted_processes[@]}"
do
    read -r -a process_info <<< "$process"
    process_id=${process_info[0]}
    burst_time=${process_info[1]}
    
    # Execute the job
    execute_job $process_id $burst_time &
    
    # Update total turnaround time
    current_time=$(date +%s)
    turnaround_time=$((current_time - start_time))
    total_turnaround_time=$((total_turnaround_time + turnaround_time))
done

# Wait for all jobs to finish
wait

# Calculate average turnaround time
num_processes=${#sorted_processes[@]}
average_turnaround_time=$(bc <<< "scale=2; $total_turnaround_time / $num_processes")

# Print results
echo "Average turnaround time: $average_turnaround_time"
