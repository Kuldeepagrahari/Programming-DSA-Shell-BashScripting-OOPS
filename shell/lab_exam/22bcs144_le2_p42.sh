#!/bin/bash
pageFaults() {
    pages=("$@")
    n=${#pages[@]}
    capacity=$1
    declare -A s
    declare -A indexes
    page_faults=0
    placements=0
    replacements=0

    for ((i=0; i<n; i++)); do
        if [ ${#s[@]} -lt $capacity ]; then
            if [ -z "${s[${pages[$i]}]}" ]; then
                ((placements++))
                s[${pages[$i]}]=1
                ((page_faults++))
            fi
            indexes[${pages[$i]}]=$i
        else
            if [ -z "${s[${pages[$i]}]}" ]; then
                lru=999999999
                for page in "${!s[@]}"; do
                    if [ ${indexes[$page]} -lt $lru ]; then
                        lru=${indexes[$page]}
                        val=$page
                    fi
                done
                unset s[$val]
                s[${pages[$i]}]=1
                ((page_faults++))
            fi
            indexes[${pages[$i]}]=$i
        fi
    done

    echo "Page faults $page_faults"
    echo "Page placements $placements"
    echo "Page replacements $((page_faults - placements))"
}
read -a pages
read capacity
pageFaults $capacity "${pages[@]}"

# lru