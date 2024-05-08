#!/bin/bash

# File to store balance
balance_file="balance.txt"

# Function to read balance from file
read_balance() {
    if [ -f "$balance_file" ]; then
        balance=$(<"$balance_file")
    else
        echo "$balance" > "$balance_file"
    fi
}

# Function to write balance to file
write_balance() {
    echo "$balance" > "$balance_file"
}

# Function to deposit money
deposit() {
    read_balance
    amount=$1
    balance=$((balance + amount))
    write_balance
    echo "You deposited $amount. Your new balance is: \$$balance"
}

# Function to withdraw money
withdraw() {
    read_balance
    amount=$1
    if [ $amount -le $balance ]; then
        balance=$((balance - amount))
        write_balance
        echo "You withdrew $amount. Your new balance is: \$$balance"
    else
        echo "Insufficient funds"
    fi
}

# Main function
main() {
    while true; do
        read -p "Enter action (deposit or withdraw) and amount (e.g., 'deposit 100'): " action amount
        # Validate input
        if [[ ! $action =~ ^(deposit|withdraw)$ || ! $amount =~ ^[0-9]+$ ]]; then
            echo "Invalid input. Please enter in the format: action amount"
            continue
        fi
        # Perform action with file lock
        (
            flock -x 200
            case $action in
                deposit)
                    deposit $amount
                    ;;
                withdraw)
                    withdraw $amount
                    ;;
            esac
        ) 200>"$balance_file.lock"
    done
}

# Start the script
main
