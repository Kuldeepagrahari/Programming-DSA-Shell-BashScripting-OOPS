#!/bin/bash

# Function to simulate MFU algorithm
mfu() {
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
                local mfu_page=$(get_mfu_page)
                frames[$mfu_page]=$page
                ((replacements++))
            fi
        else
            ((placements++))
        fi
    done

    echo "MFU:"
    echo "Page faults: $page_faults"
    echo "Placements: $placements"
    echo "Replacements: $replacements"
}

# Function to get the index of the most frequently used page
get_mfu_page() {
    local max_count=${page_count[${frames[0]}]}
    local mfu_page=0

    for i in "${!frames[@]}"; do
        local count=${page_count[${frames[$i]}]}
        if [ "$count" -gt "$max_count" ]; then
            max_count=$count
            mfu_page=$i
        fi
    done

    echo $mfu_page
}

# Main function to run the MFU simulation
main() {
    echo "Enter the page reference string (separated by spaces):"
    read -r page_ref_string

    echo "Enter the frame capacity:"
    read -r frame_size

    mfu
}

main

