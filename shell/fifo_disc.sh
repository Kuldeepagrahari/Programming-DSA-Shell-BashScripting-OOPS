#!/bin/bash

present() {
    local page=$1
    for item in "${table_frame[@]}"; do
        if [[ $page -eq $item ]]; then
            return 1
        fi
    done
    return 0
}

printtable() {
    for item in "${table_frame[@]}"; do
        if [[ $item -eq -1 ]]; then
            printf -- "-- "
        else
            printf -- "%2d " "$item"
        fi
    done
    printf -- "||"
}

# Main script starts here
read -p "Enter number of frames: " nf
read -p "Enter total number of page requests: " n

# Initialize table_frame and pages arrays
declare -a table_frame
declare -a pages

for ((i=0; i<nf; i++)); do
    table_frame[$i]=-1
done

echo "Enter reference string: "
for ((i=0; i<n; i++)); do
    read page
    pages[$i]=$page
done

count1=0

echo "Position of frame table after each request"
for ((i=0; i<n; i++)); do
    echo -n "Page table after request from ${pages[$i]} || "
    if ! present "${pages[$i]}"; then
        table_frame[$pos]=${pages[$i]}
        pos=$(( (pos+1)%nf )) # considering it as a queue
        printtable
        echo "page fault"
        ((count1++))
        continue
    fi
    printtable
    echo
done

echo -e "\nNumber of page faults: $count1\n"
