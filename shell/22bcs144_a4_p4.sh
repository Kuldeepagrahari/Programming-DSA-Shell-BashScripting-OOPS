#!/bin/sh
echo "sam"


read n
sum=0
fun(){
  for(( i=0;i<=$1;i+=2 ))
  do
    sum=$(($sum+$i))
  done
 
}
fun $n
echo "sum of even nos:"
echo $sum
