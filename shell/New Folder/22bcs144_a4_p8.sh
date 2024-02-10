#!/bin/sh


read str
echo $str
len = ${#str}
ans=0
for (( i=0;i<len;i++ ))
do
  if [ ${str:$i:1} == 'a' || ${str:$i:1} == 'e' || ${str:$i:1} == 'i' || ${str:$i:1} == '0'       ||    ${str:$i:1} == 'u'];
  then
      ans++
  fi
  
done
  
echo ans
echo $len



