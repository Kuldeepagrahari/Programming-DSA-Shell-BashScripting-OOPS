#!/bin/bash

# Function to simulate Second Chance algorithm
secondChance() {
    local page_refs=($page_ref_string)
    local frames=()
    local page_faults=0
    local placements=0
    local replacements=0
    local -a reference_bit=()
    local ptr=0

    for page in "${page_refs[@]}"; do
        if [[ ! " ${frames[@]} " =~ " $page " ]]; then
            ((page_faults++))
            if [ ${#frames[@]} -lt $frame_size ]; then
                frames+=($page)
                reference_bit[$ptr]=0
                ((placements++))
            else
                local replaced=0
                while true; do
                    if [ ${reference_bit[$ptr]} -eq 0 ]; then
                        frames[$ptr]=$page
                        reference_bit[$ptr]=0
                        ((replacements++))
                        replaced=1
                        break
                    else
                        reference_bit[$ptr]=0
                        ((ptr=(ptr+1)%frame_size))
                        if [ $ptr -eq 0 ]; then
                            # One full pass, reset all reference bits to 0
                            for ((i=0; i<$frame_size; i++)); do
                                reference_bit[$i]=0
                            done
                        fi
                    fi
                    # If we've checked all frames without replacing, break the loop
                    if [ $replaced -eq 0 ] && [ $ptr -eq 0 ]; then
                        break
                    fi
                done
            fi
        else
            ((placements++))
        fi

        ((ptr=(ptr+1)%frame_size))
    done

    echo "Second Chance:"
    echo "Page faults: $page_faults"
    echo "Placements: $placements"
    echo "Replacements: $replacements"
}

# Main function to run the Second Chance simulation
main() {
    echo "Enter the page reference string (separated by spaces):"
    read -r page_ref_string

    echo "Enter the frame capacity:"
    read -r frame_size

    secondChance
}

main