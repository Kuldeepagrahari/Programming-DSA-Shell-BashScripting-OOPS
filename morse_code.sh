#!/bin/bash

declare -A morse_code

# Define Morse code mappings
morse_code['A']='.-' morse_code['B']='-...' morse_code['C']='-.-.' morse_code['D']='-..'  morse_code['E']='.'    morse_code['F']='..-.' morse_code['G']='--.'  morse_code['H']='....' morse_code['I']='..'   morse_code['J']='.---'
morse_code['K']='-.-' morse_code['L']='.-..' morse_code['M']='--'   morse_code['N']='-.'   morse_code['O']='---'  morse_code['P']='.--.' morse_code['Q']='--.-' morse_code['R']='.-.'  morse_code['S']='...'  morse_code['T']='-'
morse_code['U']='..-' morse_code['V']='...-' morse_code['W']='.--'  morse_code['X']='-..-' morse_code['Y']='-.--' morse_code['Z']='--..' morse_code['1']='.----' morse_code['2']='..---' morse_code['3']='...--' morse_code['4']='....-'
morse_code['5']='.....' morse_code['6']='-....' morse_code['7']='--...' morse_code['8']='---..' morse_code['9']='----.' morse_code['0']='-----' morse_code[' ']='/' morse_code['.']='.-.-.-' morse_code[',']='--..--'
morse_code['?']='..--..' morse_code['!']='-.-.--' morse_code['\']='.-..-.' morse_code['/']='-..-.' morse_code['(']='-.--.' morse_code[')']='-.--.-'

# Function to convert text to Morse code
text_to_morse() {
    local text=$1
    local morse=""
    local len=${#text}

    for ((i=0; i<len; i++)); do
        local char="${text:$i:1}"
        char=${char^^}  # Convert to uppercase
        morse+=" ${morse_code[$char]}"
    done

    echo "$morse"
}

# Function to convert Morse code to text
morse_to_text() {
    local morse=$1
    local text=""
    local len=${#morse}

    # Split Morse code into individual characters
    local morse_chars=()
    for ((i=0; i<len; i++)); do
        local char="${morse:$i:1}"
        if [[ $char == " " ]]; then
            morse_chars+=("$char")
        else
            morse_chars[${#morse_chars[@]}-1]+="$char"
        fi
    done

    # Convert Morse code characters to text
    for char in "${morse_chars[@]}"; do
        local found=0
        for key in "${!morse_code[@]}"; do
            if [[ "${morse_code[$key]}" == "$char" ]]; then
                text+="$key"
                found=1
                break
            fi
        done
        if [[ $found -eq 0 ]]; then
            text+="?"
        fi
    done

    echo "$text"
}

# Main loop
while true; do
    echo "Choose an option:"
    echo "1. Text to Morse code"
    echo "2. Morse code to Text"
    echo "3. Exit"
    read -r choice

    case $choice in
        1)
            echo "Enter text to convert to Morse code:"
            read -r input_text
            echo "Morse code: $(text_to_morse "$input_text")"
            ;;
        2)
            echo "Enter Morse code to convert to text:"
            read -r input_morse
            echo "Text: $(morse_to_text "$input_morse")"
            ;;
        3)
            echo "Exiting program."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter a valid option."
            ;;
    esac
done
