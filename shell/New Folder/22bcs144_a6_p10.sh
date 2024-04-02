#!/bin/bash

# Lock function
acquire_lock() {
    # Check if lock file exists
    while [ -f lock ]; do
        sleep 1
    done
    # Create lock file
    touch lock
    echo "Process $$ acquired the lock on the resource."
}

# Unlock function
release_lock() {
    # Remove lock file
    rm lock
    echo "Process $$ released the lock on the resource."
}

# Main script
acquire_lock
# Critical section
sleep 5
release_lock
