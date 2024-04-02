#!/bin/bash

# Function for traffic light simulation
traffic_light() {
    while true; do
        echo "Traffic light: Red (stays red for 5 seconds)"
        sleep 5
        echo "Traffic light: Yellow (stays yellow for 2 seconds)"
        sleep 2
        echo "Traffic light: Green (stays green for 3 seconds)"
        sleep 3
    done
}

# Start traffic light simulation
traffic_light
