#!/bin/bash

# Initialize balance
balance=150

# Function for deposit
deposit() {
    amount=$1
    ((balance += amount))
    echo "You deposited \$$amount. Your new balance is: \$$balance"
}

# Function for withdraw
withdraw() {
    amount=$1
    if ((amount <= balance)); then
        ((balance -= amount))
        echo "You withdrew \$$amount. Your new balance is: \$$balance"
    else
        echo "Insufficient funds!"
    fi
}

# Main script
while true; do
    read -p "Enter action (deposit/withdraw) and amount: " action amount
    case $action in
    deposit)
        deposit "$amount"
        ;;
    withdraw)
        withdraw "$amount"
        ;;
    *)
        echo "Invalid action. Please enter 'deposit' or 'withdraw'."
        ;;
    esac
done
