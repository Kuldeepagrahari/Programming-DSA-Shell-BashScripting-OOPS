#!/bin/bash

# Define a function to execute a job
execute_job() {
    job_id=$1
    burst_time=$2
    sleep $burst_time
    end_time=$(date +%s)
    echo "Job $job_id finished at time $end_time"
}

# Array of process IDs, arrival times, burst times, and remaining burst times
processes=(
    "P1 0 5"
    "P2 1 3"
    "P3 2 1"
    "P4 3 2"
    "P5 4 3"
)

# Initialize time quantum
time_quantum=2

# Initialize total waiting time and total turnaround time
total_waiting_time=0
total_turnaround_time=0

# Execute processes using Round Robin scheduling
for process in "${processes[@]}"
do
    read -r -a process_info <<< "$process"
    process_id=${process_info[0]}
    arrival_time=${process_info[1]}
    burst_time=${process_info[2]}
    
    # Simulate arrival time
    current_time=$(date +%s)
    if [ $current_time -lt $arrival_time ]; then
        sleep $((arrival_time - current_time))
    fi
    
    # Execute the job with time quantum
    remaining_burst_time=$burst_time
    while [ $remaining_burst_time -gt 0 ]
    do
        if [ $remaining_burst_time -gt $time_quantum ]; then
            execute_job $process_id $time_quantum
            remaining_burst_time=$((remaining_burst_time - time_quantum))
        else
            execute_job $process_id $remaining_burst_time
            waiting_time=$((current_time - arrival_time - burst_time))
            total_waiting_time=$((total_waiting_time + waiting_time))
            total_turnaround_time=$((total_turnaround_time + waiting_time + burst_time))
            break
        fi
    done
done

# Calculate average waiting time and average turnaround time
num_processes=${#processes[@]}
average_waiting_time=$(bc <<< "scale=2; $total_waiting_time / $num_processes")
average_turnaround_time=$(bc <<< "scale=2; $total_turnaround_time / $num_processes")

# Print results
echo "Average waiting time: $average_waiting_time"
echo "Average turnaround time: $average_turnaround_time"
