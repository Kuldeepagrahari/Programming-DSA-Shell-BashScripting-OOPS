#!/bin/bash

simulate_traffic_light() {
    local color="$1"
    local duration="$2"
    
    echo "Traffic light is $color"
    
    sleep "$duration"
}

control_traffic_light() {
    while true; do
        simulate_traffic_light "red" 5
        
        simulate_traffic_light "yellow" 2
        
        simulate_traffic_light "green" 3
        
    done
}

control_traffic_light &
control_pid=$!

read -p "Press enter to stop the simulation..." input

kill "$control_pid"

