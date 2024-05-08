#!/bin/bash

find_page_index() {
  local page=$1
  for i in "${!frames[@]}"; do
    if [[ "${frames[$i]}" = "$page" ]]; then
      echo "$i"
      return
    fi
  done
  echo "-1"
}

find_lru_index() {
  local min=${times[0]}
  local index=0
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

for t in "${!pages[@]}"; do
  page=${pages[t]}
  index=$(find_page_index "$page")

  if [[ "$index" = "-1" ]]; then
    if [[ "${#frames[@]}" -lt "$num_frames" ]]; then
      frames+=("$page")
      times+=("$t")
      ((placements++))
    else
      lru_index=$(find_lru_index)
      frames[lru_index]="$page"
      times[lru_index]="$t"
      ((placements++))
      ((replacements++))
    fi
    ((page_faults++))
  else
    times[$index]=$t
  fi
done
((page_faults++))
((replacements))

echo "Page Faults: $page_faults"
echo "Placements: $placements"
echo "Replacements: $replacements"
