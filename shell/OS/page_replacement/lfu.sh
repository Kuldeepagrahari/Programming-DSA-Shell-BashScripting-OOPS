#!/bin/bash

# Function to simulate LFU algorithm
lfu() {
    local page_refs=($page_ref_string)
    local frames=()
    local page_faults=0
    local placements=0
    local replacements=0
    declare -A page_count

    for page in "${page_refs[@]}"; do
        if [ ${page_count[$page]+_} ]; then
            ((page_count[$page]++))
        else
            page_count[$page]=1
        fi

        if [[ ! " ${frames[@]} " =~ " $page " ]]; then
            ((page_faults++))
            if [ ${#frames[@]} -lt $frame_size ]; then
                frames+=($page)
                ((placements++))
            else
                local lfu_page=$(get_lfu_page)
                frames[$lfu_page]=$page
                ((replacements++))
            fi
        else
            ((placements++))
        fi
    done

    echo "LFU:"
    echo "Page faults: $page_faults"
    echo "Placements: $placements"
    echo "Replacements: $replacements"
}

# Function to get the index of the least frequently used page
get_lfu_page() {
    local min_count=${page_count[${frames[0]}]}
    local lfu_page=0

    for i in "${!frames[@]}"; do
        local count=${page_count[${frames[$i]}]}
        if [ "$count" -lt "$min_count" ]; then
            min_count=$count
            lfu_page=$i
        fi
    done

    echo $lfu_page
}

# Main function to run the LFU simulation
main() {
    echo "Enter the page reference string (separated by spaces):"
    read -r page_ref_string

    echo "Enter the frame capacity:"
    read -r frame_size

    lfu
}

main