#!/bin/bash

# Function for producer
producer() {
    while true; do
        data="This is some data."
        echo "Producer: Produced data: \"$data\"" > data.txt
        sleep 1
    done
}

# Function for consumer
consumer() {
    while true; do
        if [ -f data.txt ]; then
            data=$(cat data.txt)
            echo "Consumer: Processed data: \"$data\""
            rm data.txt
        fi
        sleep 1
    done
}

# Creating child processes
producer & producer_pid=$!
consumer & consumer_pid=$!

# Wait for child processes to finish
wait $producer_pid
wait $consumer_pid
