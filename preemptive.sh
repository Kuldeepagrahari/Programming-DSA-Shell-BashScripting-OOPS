#!/bin/bash
echo "PIDs, arrival times, burst times, and priorities"
pid=("P1" "P2" "P3" "P4" "P5")
at=(0 2 1 4 6)
bt=(5 2 3 4 1)
priorities=(3 1 2 2 3)
rem=("${bt[@]}")

total=${#pid[@]}
totalWT=0
totalTAT=0
completed=0
curr=0
prev=-1

while (( completed < total ))
do
  highest=-1
  maxPriority=-1
  for (( i=0; i<total; i++ ))
  do
    if (( at[i] <= curr && priorities[i] > maxPriority && rem[i] > 0 ))
    then
      maxPriority=${priorities[i]}
      highest=$i
    fi
  done

  if (( highest != -1 ))
  then
    rem[highest]=$((rem[highest] - 1))
    curr=$((curr + 1))

    if (( rem[highest] == 0 ))
    then
      completed=$((completed + 1))
      TATs[highest]=$((curr - at[highest]))
      WTs[highest]=$((TATs[highest] - bt[highest]))
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

avgWT="$(( totalWT / total ))"
avgTAT="$(( totalTAT / total ))"

echo "Average Waiting Time: $avgWT"
echo "Average Turnaround Time: $avgTAT"

echo "Process IDs: ${pid[@]}"
echo "Arrival Times: ${at[@]}"
echo "Burst Times: ${bt[@]}"
echo "Priorities: ${priorities[@]}"
echo "Remaining Times: ${rem[@]}"
echo "Waiting Times: ${WTs[@]}"
echo "Turnaround Times: ${TATs[@]}"