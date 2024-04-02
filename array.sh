
for (( i = 0;i < 5; i++ ))
do
read  array[$i]
done

printf " $size "
# append
array+=("golf","cricket")
# size
size="${#array[@]}"
for (( i = 0 ;i < size; i++ ))
do
  printf "%s " "${array[$i]}"
done

# subarray
arr=("${array[@]:2:3}")
size2="${#arr[@]}"
for (( i = 0 ;i < size2; i++ ))
do
  printf "%s " "${arr[$i]}"
done