#!/bin/bash


page_in_memory() {
    local page=$1
    for mem_page in "${memory[@]}"; do
        if [ $mem_page -eq $page ]; then
            return 0
        fi
    done
    return 1
}

echo "Enter the number of frames:"
read num_frames

echo "Enter the number of pages:"
read num_pages

echo "Enter the page reference string:"
read page_reference

# Initialize memory frames as empty (-1 represents empty frame)
memory=()
for ((i=0; i<num_frames; i++)); do
    memory[$i]=-1
done

# Variables to track page faults and placements
page_faults=0
placements=0

# Iterate over page reference string
for page in "${page_reference[@]}"; do
    if ! page_in_memory $page; then
        ((page_faults++))
        # Replace the oldest page in memory with the new page
        oldest_page_index=0
        for ((i=1; i<num_frames; i++)); do
            if [ ${memory[$i]} -lt ${memory[$oldest_page_index]} ]; then
                oldest_page_index=$i
            fi
        done
        memory[$oldest_page_index]=$page
    fi
    ((placements++))
    echo "Page $page: ${memory[@]}"
done

echo "Total page faults: $page_faults"
echo "Total placements: $placements"
