read op
printf "enter elements"
read a
read b
ans=0
if [[ $op = "plus" ]];
then
ans=$((a+b))
elif [[ $op = "sub" ]];
then
ans=$((a-b))
elif [[ $op = "mul" ]];
then
ans=$((a*b))
else
ans=$((a/b))
fi
printf "$ans"

