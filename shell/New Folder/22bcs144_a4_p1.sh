#!/bin/sh

fun(){
   return $(( $1 * $1 ))
}
read n
fun
for (( i=1;i<=n;i++ ))
do
fun $i
echo $?
done
