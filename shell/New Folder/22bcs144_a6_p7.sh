#!/bin/bash

# Function for sending message
send_message() {
    while true; do
        read -p "[User$1]:" message
        echo "[User$1]: $message"
    done
}

# Creating child processes for users
send_message 1 & user1_pid=$!
send_message 2 & user2_pid=$!

# Wait for child processes to finish
wait $user1_pid
wait $user2_pid
