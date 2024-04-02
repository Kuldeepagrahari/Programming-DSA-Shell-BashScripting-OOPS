#!/bin/bash

# Shared file path on the desktop
file="$HOME/Desktop/copy.txt"

# Initialize file
echo "" > $file

# Function for the producer process
producer() {
    for i in {1..5}; do
        data="This is some data."
        echo "Producer: Produced data: \"$data\""
        echo "$data" >> $file
        sleep 1
    done
}

# Function for the consumer process
consumer() {
    while true; do
        if [ -s $file ]; then
            data=$(head -n 1 $file)
            echo "Consumer: Processed data: \"$data\""
            sed -i '1d' $file
        fi
        sleep 1
    done
}

# Start producer and consumer processes in the background
producer &
consumer &

# Wait for both processes to finish
wait

