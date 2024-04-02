
read num
for (( i = 0;i < num; i++ ))
do
read  array[$i]
done

printf " $size "
maxi=0
# size
size="${#array[@]}"
for (( i = 0 ;i < size; i++ ))
do
  if [[ ${array[$i]} > $maxi ]];
  then
  maxi="${array[$i]}"
  fi
done
printf "maxi is : $maxi"