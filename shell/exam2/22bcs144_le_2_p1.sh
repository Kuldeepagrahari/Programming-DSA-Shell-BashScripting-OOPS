#!/bin/bash

echo "Process IDs, arrival times, and burst times"
pid=("P1" "P2" "P3" "P4")
at=(0 1 2 3)
bt=(5 3 6 4)
remaining=("${bt[@]}")

total=${#pid[@]}
totalWT=0
totalTAT=0
completed=0
curr=0
prev=-1

while (( completed < total ))
do
  shortest=-1
  minRemTime=99999
  for (( i=0; i<total; i++ ))
  do
    if (( at[i] <= curr && remaining[i] < minRemTime && remaining[i] > 0 ))
    then
      minRemTime=${remaining[i]}
      shortest=$i
    fi
  done

 # If process is found, update remaining time and current time
  if (( shortest != -1 ))
  then
    remaining[shortest]=$((remaining[shortest] - 1))
    curr=$((curr + 1))

    # If process has finished, update turnaround time and completed process count
    if (( remaining[shortest] == 0 ))
    then
      completed=$((completed + 1))
      TATs[shortest]=$((curr - at[shortest]))
      WTs[shortest]=$((TATs[shortest] - bt[shortest]))
    fi
  else
    curr=$((curr + 1))
  fi
done

for (( i=0; i<total; i++ ))
do
  totalWT=$((totalWT + WTs[i]))
  totalTAT=$((totalTAT + TATs[i]))
done

avgWT=$(echo "scale=2; $totalWT / $total" | bc)
avgTAT=$(echo "scale=2; $totalTAT / $total" | bc)
echo "Average Waiting Time: $avgWT"
echo "Average Turnaround Time: $avgTAT"

echo "Process IDs: ${pid[@]}"
echo "Arrival Times: ${at[@]}"
echo "Burst Times: ${bt[@]}"
echo "Remaining Times: ${remaining[@]}"
echo "Waiting Times: ${WTs[@]}"
echo "Turnaround Times: ${TATs[@]}"