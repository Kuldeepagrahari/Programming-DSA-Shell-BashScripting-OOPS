#!/bin/bash

echo "DINING PHILOSOPHER PROBLEM"
read -p "Enter the total no. of philosophers: " total_philosophers
read -p "How many are hungry: " hungry_philosophers

positions=()
fork=() 

for ((i=0; i<total_philosophers; i++)); do
    fork[$i]=0  
done

for ((i=0; i<hungry_philosophers; i++)); do
    read -p "Enter philosopher $((i+1)) position: " position
    positions+=($position)
done

check_eating() {
    local philosopher=$1
    local left=$((philosopher % total_philosophers))
    local right=$((($philosopher + 1) % total_philosophers))

    if [ ${fork[$left]} -eq 0 ] && [ ${fork[$right]} -eq 0 ]; then
        fork[$left]=1
        fork[$right]=1
        echo "P $philosopher is granted to eat"
        sleep 1
        fork[$left]=0
        fork[$right]=0
        echo "P $philosopher is waiting"
    else
        echo "P $philosopher is waiting"
    fi
}

while true; do
    echo "1. One can eat at a time"
    echo "2. Two can eat at a time"
    echo "3. Exit"
    read -p "Enter your choice: " choice

    case $choice in
        1)
            echo "Allow one philosopher to eat at any time"
            for p in "${positions[@]}"; do
                check_eating $p
            done
            ;;
        2)
            echo "Allow two philosophers to eat at the same time"
            combinations=()
            for ((i=0; i<${#positions[@]}; i++)); do
                for ((j=i+1; j<${#positions[@]}; j++)); do
                    combinations+=("${positions[i]} ${positions[j]}")
                done
            done

            for c in "${combinations[@]}"; do
                read left right <<< $c
                echo "Combination $left and $right are granted to eat"
                sleep 1
                echo "P $left is waiting"
                echo "P $right is waiting"
            done
            ;;
        3)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid choice"
            ;;
    esac
done
