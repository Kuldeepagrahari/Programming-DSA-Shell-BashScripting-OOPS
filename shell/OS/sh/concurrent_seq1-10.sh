#!/bin/bash

a=0

child1() {
    for ((i = 1; i <= 10; i += 2)); do
        echo "process 1: $i"
        sleep 1
    done
}

child2() {
    for ((i = 2; i <= 10; i += 2)); do
        echo "process 2: $i"
        sleep 1
    done
}

child1 &
child1_pid=$!
child2 &
child2_pid=$!

wait $child1_pid
wait $child2_pid
