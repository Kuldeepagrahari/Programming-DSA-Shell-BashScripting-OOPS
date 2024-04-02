
fact=1
facto (){
        num=$1
        for (( i = 1; i<= num; i++ ))
        do 
        fact=$(( fact*i ))
        done
}
facto 5
printf "$fact"