


fib2(){
   fib1=0
   fib2=1
   $t
   for (( i=0;i<$1;i++ ))
   do
     t=$fib2
     fib2=$(( $fib1 + $fib2 ))
     fib1=$t
     echo "$fib2"
   done
   
   return $fib2
}
read n
fib2 $n

