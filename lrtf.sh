#!/bin/bash

# Initialize process IDs, burst times, and arrival times
process_ids=(0 1 2)
burst_times=(2 4 8)
arrival_times=(0 0 0)

# Initialize other variables
num_processes=${#process_ids[@]}
completion_times=()
turnaround_times=()
total_turnaround_time=0

# Function to find the process with the longest remaining time
find_longest_remaining_time() {
  max_index=0
  max_value=${remaining_times[0]}
  for (( i=1; i<$num_processes; i++ ))
  do
    if (( remaining_times[i] > max_value ))
    then
      max_index=$i
      max_value=${remaining_times[i]}
    fi
  done
  echo $max_index
}

# Initialize remaining times to burst times
remaining_times=("${burst_times[@]}")

# Main loop to process each unit of time
for (( time=0; ; time++ ))
do
  # Find the process with the longest remaining time
  longest_remaining_time=$(find_longest_remaining_time)

  # If all processes are complete, break the loop
  if (( remaining_times[longest_remaining_time] == 0 ))
  then
    break
  fi

  # Decrease the remaining time of the selected process
  ((remaining_times[longest_remaining_time]--))

  # If the process has completed, calculate its completion time and turnaround time
  if (( remaining_times[longest_remaining_time] == 0 ))
  then
    completion_times[longest_remaining_time]=$((time+1))
    turnaround_times[longest_remaining_time]=$((completion_times[longest_remaining_time]-arrival_times[longest_remaining_time]))
    total_turnaround_time=$((total_turnaround_time+turnaround_times[longest_remaining_time]))
  fi
done

# Calculate and print the average turnaround time
average_turnaround_time="$(( total_turnaround_time / num_processes ))"
echo "Average turnaround time: $average_turnaround_time"
