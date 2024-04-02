#!/bin/bash

echo"Process IDs, arrival times, and burst times"
pid=("P1" "P2" "P3")
at=(0 0 0)
bt=(2 4 8)
rem=("${bt[@]}")

total=${#pid[@]}
totalWT=0
totalTAT=0
completed=0
curr=0
prev=-1

while (( completed < total ))
do
  longest=-1
  maxRT=-1
  for (( i=0; i<total; i++ ))
  do
    if (( at[i] <= curr && rem[i] > maxRT ))
    then
      maxRT=${rem[i]}
      longest=$i
    fi
  done

  if (( longest != -1 ))
  then
    rem[longest]=$((rem[longest] - 1))
    curr=$((curr + 1))

    if (( rem[longest] == 0 ))
    then
      completed=$((completed + 1))
      TATs[longest]=$((curr - at[longest]))
      WTs[longest]=$((TATs[longest] - bt[longest]))
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
echo "Remaining Times: ${rem[@]}"
echo "Waiting Times: ${WTs[@]}"
echo "Turnaround Times: ${TATs[@]}"