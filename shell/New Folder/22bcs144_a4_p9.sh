#!/bin/sh


fun(){
  str=""
  str=$1
  str2=""
  for (( i=$2;i<=$3;i++ ))
  do
    str2+=${str:$i:1}
  done
  
}
read s1
read s2
s3=${s1}${s2}
echo $s3

read x
read y
fun $s1 $x $y
echo $str2
