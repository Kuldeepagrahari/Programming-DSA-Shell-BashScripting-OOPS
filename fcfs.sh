#!/bin/bash

echo "Enter the number of processes:"
read n

for (( i=0; i<$n; i++ ))
do
    echo "Enter arrival time for process $((i+1)):"
    read arrival[$i]
    echo "Enter burst time for process $((i+1)):"
    read burst[$i]
    process[$i]=$((i+1))
done

# Sort processes by arrival time
for (( i=0; i<$n; i++ ))
do
    for (( j=0; j<$((n-1)); j++ ))
    do
        if (( ${arrival[$j]} > ${arrival[$((j+1))]} ))
        then
            temp=${arrival[$j]}
            arrival[$j]=${arrival[$((j+1))]}
            arrival[$((j+1))]=$temp

            temp=${burst[$j]}
            burst[$j]=${burst[$((j+1))]}
            burst[$((j+1))]=$temp

            temp=${process[$j]}
            process[$j]=${process[$((j+1))]}
            process[$((j+1))]=$temp
        fi
    done
done

echo "ProcessOrder Process ArrivalTime BurstTime WaitingTime TurnaroundTime"
totalwt=0
totaltat=0
currentTime=0
for (( i=0; i<$n; i++ ))
do
    if (( currentTime < arrival[$i] ))
    then
        currentTime=${arrival[$i]}
    fi
    waiting[$i]=$((currentTime-arrival[$i]))
    turnaround[$i]=$((waiting[$i]+burst[$i]))
    totalwt=$((totalwt+waiting[$i]))
    totaltat=$((totaltat+turnaround[$i]))
    currentTime=$((currentTime+burst[$i]))
    echo "$((i+1)) P${process[$i]} ${arrival[$i]} ${burst[$i]} ${waiting[$i]} ${turnaround[$i]}"
done

echo "Average waiting time: $(( totalwt / n ))"
echo "Average turnaround time: $(( totaltat / n ))"
