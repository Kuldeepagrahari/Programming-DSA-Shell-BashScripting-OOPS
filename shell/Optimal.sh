#!/bin/bash

# Function to find if a page is present in memory
contains() {
  local e match="$1"
  shift
  for e; do [[ "$e" == "$match" ]] && return 0; done
  return 1
}

# Function to find the farthest page in the future
find_farthest() {
  local -n ref_string_ref=$1
  local -n frames_ref=$2
  local farthest_index=0
  local i
  for i in "${!frames_ref[@]}"; do
    local j
    for j in "${!ref_string_ref[@]}"; do
      if [[ "${frames_ref[$i]}" == "${ref_string_ref[$j]}" ]]; then
        if [[ "$j" -gt "$farthest_index" ]]; then
          farthest_index=$j
        fi
        break
      fi
    done
  done
  echo $farthest_index
}

# Optimal page replacement algorithm
optimal() {
  local capacity=$1
  shift
  local pages=("$@")
  local frames=()
  local page_faults=0
  local placements=0
  local replacements=0

  for page in "${pages[@]}"; do
    if ! contains "$page" "${frames[@]}"; then
      ((page_faults++))
      if (( ${#frames[@]} < capacity )); then
        frames+=("$page")
        ((placements++))
        echo "Page $page placed into memory. Current state: ${frames[@]}"
      else
        local farthest=$(find_farthest pages frames)
        echo "Page ${frames[$farthest]} replaced by $page. Current state: ${frames[@]}"
        frames[$farthest]="$page"
        ((replacements++))
      fi
    else
      echo "Page $page already in memory. Current state: ${frames[@]}"
    fi
  done

  echo "Page Faults: $page_faults"
  echo "Placements: $placements"
  echo "Replacements: $replacements"
}
# Take capacity as input from the user
echo "Enter the capacity:"
read capacity
echo "Enter the reference string:"
read -a pages

optimal $capacity "${pages[@]}"