#!/bin/bash

pageFaults() {
    local -a pages=("$@")
    local n=${#pages[@]}
    local capacity=$1
    local -A s
    local -a indexes=()
    local page_faults=0
    local placements=0
    local replacements=0

    for ((i=0; i<n; i++)); do
        if (( ${#s[@]} < capacity )); then
            if [[ -z ${s[${pages[i]}]} ]]; then
                ((placements++))
                s[${pages[i]}]=1
                ((page_faults++))
                indexes+=(${pages[i]})
            fi
        else
            if [[ -z ${s[${pages[i]}]} ]]; then
                ((replacements++))
                val=${indexes[0]}
                unset 'indexes[0]'

                unset s[$val]

                s[${pages[i]}]=1
                indexes+=(${pages[i]})
                ((page_faults++))
            fi
        fi
    done

    echo "Page faults $page_faults"
    echo "Page placements $placements"
    echo "Page replacements $replacements"
}

read -a pages
read capacity
pageFaults $capacity "${pages[@]}"

#fifo