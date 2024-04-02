#!/bin/bash

# Function to display the Tic-Tac-Toe board
display_board() {
    clear
    echo " ${board[0]} | ${board[1]} | ${board[2]}"
    echo "---|---|---"
    echo " ${board[3]} | ${board[4]} | ${board[5]}"
    echo "---|---|---"
    echo " ${board[6]} | ${board[7]} | ${board[8]}"
}

# Function to check if a player has won
check_win() {
    # Check rows
    for ((i=0; i<9; i+=3)); do
        if [[ ${board[$i]} == $1 && ${board[$i+1]} == $1 && ${board[$i+2]} == $1 ]]; then
            return 0
        fi
    done

    # Check columns
    for ((i=0; i<3; i++)); do
        if [[ ${board[$i]} == $1 && ${board[$i+3]} == $1 && ${board[$i+6]} == $1 ]]; then
            return 0
        fi
    done

    # Check diagonals
    if [[ ${board[0]} == $1 && ${board[4]} == $1 && ${board[8]} == $1 ]]; then
        return 0
    elif [[ ${board[2]} == $1 && ${board[4]} == $1 && ${board[6]} == $1 ]]; then
        return 0
    fi

    return 1
}

# Function to check if the board is full
check_draw() {
    for ((i=0; i<9; i++)); do
        if [[ ${board[$i]} == " " ]]; then
            return 1
        fi
    done
    return 0
}

# Initialize the board
board=(" " " " " " " " " " " " " " " " " ")

# Main game loop
player="X"
while true; do
    display_board

    # Get player's move
    while true; do
        echo "Player $player's turn (1-9):"
        read -r move

        if [[ $move =~ ^[1-9]$ && ${board[$move-1]} == " " ]]; then
            break
        else
            echo "Invalid move. Please choose an empty cell (1-9)."
        fi
    done

    # Make the move
    board[$move-1]=$player

    # Check for win or draw
    check_win $player
    if [[ $? -eq 0 ]]; then
        display_board
        echo "Player $player wins!"
        break
    fi

    check_draw
    if [[ $? -eq 0 ]]; then
        display_board
        echo "It's a draw!"
        break
    fi

    # Switch player
    if [[ $player == "X" ]]; then
        player="O"
    else
        player="X"
    fi
done
