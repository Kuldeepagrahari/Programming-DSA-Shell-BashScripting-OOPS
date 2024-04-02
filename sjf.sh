#!/bin/bash

pid=("P1" "P2" "P3" "P4" "P5")
at=(3 1 4 0 2)
bt=(1 4 2 6 3)

total=${#pid[@]}
totalWT=0
sumTAT=0
completed=0
curr=0

while (( completed < total ))
do
  # find the process with shortest bt
  shortest=-1
  minBT=99999
  for (( i=0; i<total; i++ ))
  do
    if (( at[i] <= curr && bt[i] < minBT && bt[i] > 0 ))
    then
      minBT=${bt[i]}
      shortest=$i
    fi
  done
  if (( shortest != -1 ))
  then
    WTs[shortest]=$((curr - at[shortest]))
    totalWT=$((totalWT + WTs[shortest]))
    curr=$((curr + bt[shortest]))
    TATs[shortest]=$((curr - at[shortest]))
    sumTAT=$((sumTAT + TATs[shortest]))
    bt[shortest]=0
    completed=$((completed + 1))
  else
    curr=$((curr + 1))
  fi
done

echo "Process IDs: ${pid[@]}"
echo "Arrival Times: ${at[@]}"
echo "Burst Times: ${bt[@]}"
echo "Waiting Times: ${WTs[@]}"
echo "Turnaround Times: ${TATs[@]}"

avgWT=$(( totalWT / total ))
avgTAT=$(( sumTAT / total ))
echo "Average Waiting Time: $avgWT"
echo "Average Turnaround Time: $avgTAT"