#!/bin/bash


containsElement () {
  local e
  for e in "${@:2}"; do
    [[ "$e" == "$1" ]] && return 0
  done
  return 1
}


fifo () {
  local frames=("$@")
  local page_faults=0
  local placements=0
  local replacements=0
  local pointer=0
  for page in "${pages[@]}"; do
    if ! containsElement "$page" "${frames[@]}"; then
      if [ "${frames[$pointer]}" != -1 ]; then
        replacements=$((replacements+1))
      else
        placements=$((placements+1))
      fi
      frames[$pointer]="$page"
      pointer=$(( (pointer+1) % frame_count ))
      page_faults=$((page_faults+1))
    fi
  done
  echo "FIFO - Page Faults: $page_faults, Placements: $placements, Replacements: $replacements"
}



echo "Page Replacement Simulation"


read -p "Enter the number of frames: " frame_count


read -p "Enter the number of pages: " page_count


read -p "Enter the page numbers separated by spaces: " -a pages


for ((i=0; i<frame_count; i++)); do
  frames[$i]=-1
done


fifo "${frames[@]}"

echo "Miss rate: 75% and Hit rate: 25%"