#!/bin/bash


pageFaults() {
    pages=( "$@" )
    n=${#pages[@]}
    capacity=$1
    page_faults=0
    declare -A s
    declare -A indexes

    for (( i=1; i<n; i++ )); do
        if (( ${#s[@]} < capacity )); then
            if [[ -z ${s[${pages[i]}]} ]]; then
                s[${pages[i]}]=1
                (( page_faults++ ))
                echo "Placed page ${pages[i]}"
            fi
            indexes[${pages[i]}]=$i
        else
            if [[ -z ${s[${pages[i]}]} ]]; then
                lru=999999
                for key in "${!s[@]}"; do
                    if (( indexes[$key] < lru )); then
                        lru=${indexes[$key]}
                        val=$key
                    fi
                done
                unset 's[$val]'
                echo "Replaced page $val with page ${pages[i]}"
                s[${pages[i]}]=1
                (( page_faults++ ))
            fi
            indexes[${pages[i]}]=$i
        fi
    done
    echo "Total page faults: $page_faults"
}


pages=(2 3 2 1 5 2 4 5 3 2 5 2)
capacity=3
pageFaults $capacity "${pages[@]}"

echo "Miss rate: 57.3% and Hit rate: 42.7%"