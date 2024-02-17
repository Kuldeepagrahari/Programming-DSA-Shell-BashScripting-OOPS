cs() {
    s1=$1
    s2=$2

    cs="$s1$s2"
    echo "$cs"
}

es() {
    cs=$1
    si=$2
    ei=$3

    ss="${cs:$si:$((ei - si + 1))}"
    echo "$ss"
}


c=$(cs "Hi" "There")
echo "Concatenated string: $c"

s=$(es "$c" 0 1)
echo "Extracted substring: $s"
