#!/bin/sh
echo "sam"
fun(){
  local rem=0
  local rev=0
  local t=$1
  while [ $t -gt 0 ]
  do
    rem=$(( $t % 10 ))
    rev=$(( $rev * 10 + $rem ))
    t=$(( $t / 10 ))
  done
  return $rev
  
}
read n
fun $n
echo $?


