
for (( i=0;i<10;i++ ))
do
echo "sam"
done

ans = 0
for (( j=1;j<5;j++ ))
do
ans=$(( $ans+$j ))
done
echo "$ans"
