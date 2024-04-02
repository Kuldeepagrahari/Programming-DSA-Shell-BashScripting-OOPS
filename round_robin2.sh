#!/bin/bash

# Function to sort processes based on arrival time
sort_processes() {
    for ((i = 0; i < $n; i++)); do
        for ((j = 0; j < $((n - i - 1)); j++)); do
            if [ ${arrival_time[j]} -gt ${arrival_time[$((j + 1))]} ]; then
                # Swap arrival time
                temp=${arrival_time[j]}
                arrival_time[$j]=${arrival_time[$((j + 1))]}
                arrival_time[$((j + 1))]=$temp

                # Swap burst time
                temp=${burst_time[j]}
                burst_time[$j]=${burst_time[$((j + 1))]}
                burst_time[$((j + 1))]=$temp

                # Swap process ID
                temp=${pid[j]}
                pid[$j]=${pid[$((j + 1))]}
                pid[$((j + 1))]=$temp
            elif [ ${arrival_time[j]} -eq ${arrival_time[$((j + 1))]} ]; then
                if [ ${pid[j]} -gt ${pid[$((j + 1))]} ]; then
                    # Swap process ID
                    temp=${pid[j]}
                    pid[$j]=${pid[$((j + 1))]}
                    pid[$((j + 1))]=$temp
                fi
            fi
        done
    done
}

# Function to calculate waiting time, turnaround time, and completion time
calculate_metrics() {
    local t=0
    local is_completed=0
    local arrival=0

    while [ $is_completed -eq 0 ]; do
        is_completed=1
        for ((i = 0; i < $n; i++)); do
            if [ ${burst_time[$i]} -gt 0 ]; then
                is_completed=0
                if [ ${burst_time[$i]} -gt $quantum ] && [ ${arrival_time[$i]} -le $arrival ]; then
                    for ((j = 0; j < $quantum; j++)); do
                        if [ ${burst_time[$i]} -gt 0 ]; then
                            chart[$t]=${pid[$i]}
                            ((t++))
                            ((burst_time[$i]--))
                            ((arrival++))
                        fi
                    done
                else
                    if [ ${arrival_time[$i]} -le $arrival ]; then
                        ((arrival++))
                        for ((j = 0; j < ${burst_time[$i]}; j++)); do
                            chart[$t]=${pid[$i]}
                            ((t++))
                        done
                        burst_time[$i]=0
                        completion_time[$i]=$t
                    fi
                fi
            fi
        done
    done

    # Calculate waiting time and turnaround time
    for ((i = 0; i < $n; i++)); do
        tat[$i]=$((completion_time[$i] - arrival_time[$i]))
        waiting_time[$i]=$((tat[$i] - burst_time_copy[$i]))
    done

    # Print metrics
    echo "Process ID  Arrival Time  Burst Time  Waiting Time  Turnaround Time  Completion Time"
    for ((i = 0; i < $n; i++)); do
        echo -e "${pid[$i]} \t\t ${arrival_time[$i]} \t\t ${burst_time_copy[$i]} \t\t ${waiting_time[$i]} \t\t ${tat[$i]} \t\t\t ${completion_time[$i]}"
    done

    # Calculate average waiting time and turnaround time
    total_wt=0
    total_tat=0
    for ((i = 0; i < $n; i++)); do
        total_wt=$((total_wt + waiting_time[$i]))
        total_tat=$((total_tat + tat[$i]))
    done
    avgwt=$((total_wt / n))
    avgtat=$((total_tat / n))


    echo "Average Waiting Time: $avgwt"
    echo "Average Turnaround Time: $avgtat"
}

# Main program

# Input number of processes
read -p "Enter the number of processes: " n

# Input process details
for ((i = 0; i < n; i++)); do
    read -p "Enter Process ID for process $((i + 1)): " pid[$i]
    read -p "Enter Arrival Time for process $((i + 1)): " arrival_time[$i]
    read -p "Enter Burst Time for process $((i + 1)): " burst_time[$i]
    burst_time_copy[$i]=${burst_time[$i]}
done

# Input quantum size
read -p "Enter Quantum Size: " quantum

# Sort processes based on arrival time
sort_processes

# Calculate metrics
calculate_metrics
