#!/bin/sh
echo "sam"

avg(){
  aver=0
  for (( i=1;i<$1;i++ ))
  do
    aver+=$RANDOM
  done
  return $aver
}
read n
avg $n
echo $?
