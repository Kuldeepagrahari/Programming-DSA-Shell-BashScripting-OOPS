
read str
len="${#str}"
# len aur equal ke beech space nhi aana chahiye
# calculation ke liye paranthesis use karo
# paranthesis ke andar dollar $ nhi use karna
f=1
echo "$len"
for (( i = 0; i < len / 2; i++ )); do
    if [[ "${str:$i:1}" != "${str:$((len - i - 1)):1}" ]]; then
        f=0
        break
    fi
done

if [ $f = 1 ]; then
    printf "palindrome \n"
else
    echo "not palindrome"
fi
