#!/bin/bash
allocation_matrix=(
    [0]="0 1 0"
    [1]="2 0 0"
    [2]="3 0 3"
)

maximum_matrix=(
    [0]="8 4 3"
    [1]="6 2 0"
    [2]="3 3 3"
)

available_resources="3 2 2"

read -a available_resources_arr <<< "$available_resources"

declare -A allocation
declare -A maximum

for i in "${!allocation_matrix[@]}"; do
    read -a allocation_row <<< "${allocation_matrix[$i]}"
    allocation[$i]="${allocation_row[@]}"
done

for i in "${!maximum_matrix[@]}"; do
    read -a maximum_row <<< "${maximum_matrix[$i]}"
    maximum[$i]="${maximum_row[@]}"
done

work=("${available_resources_arr[@]}")
unset need
declare -A finish

for i in "${!allocation[@]}"; do
    need_row=()
    read -a allocation_row <<< "${allocation[$i]}"
    read -a maximum_row <<< "${maximum[$i]}"
    for ((j=0; j<${#allocation_row[@]}; j++)); do
        need_row[$j]=$((maximum_row[$j] - allocation_row[$j]))
    done
    need[$i]="${need_row[@]}"
    finish[$i]=0
done

safety_sequence=()
unsafe=0

for ((count=0; count<${#allocation[@]}; count++)); do
    for i in "${!allocation[@]}"; do
        if [ ${finish[$i]} -eq 0 ]; then
            read -a need_row <<< "${need[$i]}"
            safe=1
            for ((j=0; j<${#need_row[@]}; j++)); do
                if [ ${need_row[$j]} -gt ${work[$j]} ]; then
                    safe=0
                    break
                fi
            done
            if [ $safe -eq 1 ]; then
                safety_sequence+=("$i")
                read -a allocation_row <<< "${allocation[$i]}"
                for ((j=0; j<${#allocation_row[@]}; j++)); do
                    work[$j]=$((work[$j] + allocation_row[$j]))
                done
                finish[$i]=1
            fi
        fi
    done
done

for i in "${!finish[@]}"; do
    if [ ${finish[$i]} -eq 0 ]; then
        unsafe=1
        break
    fi
done

if [ $unsafe -eq 1 ]; then
    echo "Deadlock Detected!"
    echo "The processes in the deadlock are: ${!finish[@]}"
else
    echo "No deadlock detected. System is in a safe state."
fi