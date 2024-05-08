#!/bin/bash

COUNTER_FILE="/tmp/shared_counter"
echo 0 > "$COUNTER_FILE"

increment_counter() {
    local temp_file=$(mktemp)
    flock "$COUNTER_FILE" sh -c 'counter=$(<"$1"); echo $((counter + 10000)) > "$1"' _ "$COUNTER_FILE"
}

NUM_CHILDREN=5

for ((i = 1; i <= NUM_CHILDREN; i++)); do
    increment_counter $COUNTER_FILE &
done

wait

final_value=$(<"$COUNTER_FILE")
echo "Final counter value: $final_value"
