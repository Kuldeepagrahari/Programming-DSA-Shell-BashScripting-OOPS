#!/bin/sh
echo "sam"
fun(){
   local fact=1
   for (( i=1;i <= $1;i++ ))
   do
     fact=$(( $fact * $i ))

   done
   return $fact
}


for (( j=1;j<=5;j++ ))
do  
  fun $j
  echo $?
done


