#!/bin/sh
echo "sam"
isPrime() {
    num=$1

    if ((num <= 1)); then
        return 1
    fi

    for ((i = 2; i <= num / 2; i++)); do
        if ((num % i == 0)); then
            return 1
        fi
    done

    return 0
}

primes() {
    start=$1
    end=$2

    for ((num = start; num <= end; num++)); do
        if isPrime "$num"; then
            echo "$num"
        fi
    done
}

# Example usage:
primes 10 50


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
