contains() {
  local e match="$1"
  shift
  for e; do [[ "$e" == "$match" ]] && return 0; done
  return 1
}

fifo() {
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
        local replaced_page=${frames[0]}
        frames=("${frames[@]:1}" "$page")
        ((replacements++))
        echo "Page $replaced_page replaced by $page. Current state: ${frames[@]}"
      fi
    else
      echo "Page $page already in memory. Current state: ${frames[@]}"
    fi
  done

  echo "Final placement: ${frames[@]}"
  echo "Page Faults: $page_faults"
  echo "Placements: $placements"
  echo "Replacements: $replacements"
}

echo "Enter the capacity:"
read capacity
echo "Enter the reference string:"
read -a pages

fifo $capacity "${pages[@]}"