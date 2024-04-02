#!/bin/bash

# Function to check if a year is a leap year
is_leap_year() {
    year=$1
    if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; then
        echo "Leap year"
    else
        echo "Not a leap year"
    fi
}

# Function to check if the day is valid within the year
is_valid_day() {
    year=$1
    month=$2
    day=$3
    if [ $month -eq 2 ]; then
        if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; then
            days_in_month=29
        else
            days_in_month=28
        fi
    elif [ $month -eq 4 ] || [ $month -eq 6 ] || [ $month -eq 9 ] || [ $month -eq 11 ]; then
        days_in_month=30
    else
        days_in_month=31
    fi

    if [ $day -ge 1 ] && [ $day -le $days_in_month ]; then
        echo "Valid day"
    else
        echo "Invalid day"
    fi
}

# Main script
echo "Enter the year:"
read year
echo "Enter the month (1-12):"
read month
echo "Enter the day:"
read day

is_leap_year "$year"
is_valid_day "$year" "$month" "$day"
