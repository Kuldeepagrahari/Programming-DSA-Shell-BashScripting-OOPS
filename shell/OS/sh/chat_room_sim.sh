#!/bin/bash

# Maximum number of users
MAX_USERS=3

# Array to store usernames
usernames=()

# Function to display messages with username prefix
display_message() {
  local user="$1"
  local msg="$2"
  echo "[$user]: $msg"
}

# Welcome message
echo "Welcome to the simulated chat room!"

# Get usernames (limited to MAX_USERS)
user_count=0
while [[ $user_count -lt $MAX_USERS ]]; do
  read -p "Enter username (or 'quit' to exit): " username
  
  if [[ "$username" == "quit" ]]; then
    break
  fi
  
  # Check for duplicate username
  if [[ " ${usernames[@]} " =~ " $username " ]]; then
    echo "Username '$username' already taken. Please choose another."
    continue
  fi
  
  usernames+=("$username")
  echo "Welcome, $username!"
  user_count=$((user_count + 1))
done

# Check if any users joined
if [[ $user_count == 0 ]]; then
  echo "No users joined. Exiting..."
  exit 0
fi

# Loop for user input and simulated message display
current_user=0  # Track current user index
while true; do
  # Get username and message from current user
  username=${usernames[$current_user]}
  read -p "[$username]: " msg
  
  if [[ "$msg" == "quit" ]]; then
    break
  fi
  
  # Display the user's message
  display_message "$username" "$msg"
  
  # Simulate other users sending messages (excluding current user)
  for (( i=0; i<${#usernames[@]}; i++ )); do
    if [[ $i -ne $current_user ]]; then
      random_msg="This is a simulated message from ${usernames[$i]}."
      display_message "${usernames[$i]}" "$random_msg"
    fi
  done
  
  # Switch to next user (wrap around)
  current_user=$(( (current_user + 1) % ${#usernames[@]}))
done

echo "Exiting chat room..."
