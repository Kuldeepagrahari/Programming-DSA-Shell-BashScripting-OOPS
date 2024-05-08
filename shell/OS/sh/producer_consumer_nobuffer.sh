#!/bin/bash

producer() {
    echo "Producer process started..."
    for i in {1..10}; do
        echo "Producing data $i"
        echo "Data $i" >> data.txt  # Append data to file
        sleep 1  # Simulate data generation time
    done
    echo "Producer process finished."
}

# Function for the consumer process
consumer() {
    echo "Consumer process started..."
    while read -r line; do
        echo "Consuming and processing data: $line"
        sleep 2  # Simulate processing time
    done < data.txt
    echo "Consumer process finished."
}

touch data.txt

producer &
producer_pid=$!

consumer &
consumer_pid=$!

wait $producer_pid
wait $consumer_pid

echo "All processes finished."
