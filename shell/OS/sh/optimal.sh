#!/bin/bash
optimalPageFaults() {
    pages=("$@")
    n=${#pages[@]}
    capacity=$1
    declare -A s
    page_faults=0
    page_replacements=0

    for ((i=0; i<n; i++)); do
        if [ ${#s[@]} -lt $capacity ]; then
            if [ -z "${s[${pages[$i]}]}" ]; then
                s[${pages[$i]}]=$i
                ((page_faults++))
            fi
        else
            if [ -z "${s[${pages[$i]}]}" ]; then
                page_replacements=$((page_replacements + 1))
                max=-1
                replacement_page=-1
                for page in "${!s[@]}"; do
                    if [ "${s[$page]}" -gt $max ]; then
                        max=${s[$page]}
                        replacement_page=$page
                    fi
                done
                unset s[$replacement_page]
                s[${pages[$i]}]=$i
                ((page_faults++))
            fi
        fi
    done

    echo "Page Faults: $page_faults"
    echo "Page Replacements: $page_replacements"
    echo "Page placements $((page_faults - page_replacements))"
}

read capacity
read -a pages_array

optimalPageFaults $capacity "${pages_array[@]}"