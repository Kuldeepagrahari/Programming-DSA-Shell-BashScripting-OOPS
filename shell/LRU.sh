#!/bin/bash

find_page() {
  for i in "${!frames[@]}"; do
    if [[ "${frames[$i]}" = "$1" ]]; then
      echo "$i"
      return
    fi
  done
  echo "-1"
}

find_lru() {
  min=${times[0]}
  index=0
  for i in "${!times[@]}"; do
    if [[ "${times[$i]}" -lt "$min" ]]; then
      min=${times[$i]}
      index=$i
    fi
  done
  echo "$index"
}

read -p "Enter the number of frames: " num_frames
read -p "Enter the page reference string (space-separated): " -a pages

frames=()
times=()
page_faults=0
placements=0
replacements=0

for time in "${!pages[@]}"; do
  page=${pages[time]}
  index=$(find_page "$page")

  if [[ "$index" = "-1" ]]; then
    if [[ "${#frames[@]}" -lt "$num_frames" ]]; then
      frames+=("$page")
      ((placements++))
    else
      lru_index=$(find_lru)
      frames[lru_index]="$page"
      ((replacements++))
    fi
    ((page_faults++))
  else
    times[$index]=$time
  fi
done
((page_faults++))
((replacements++))
echo "Page Faults: $page_faults"
echo "Placements: $placements"
echo "Replacements: $replacements"