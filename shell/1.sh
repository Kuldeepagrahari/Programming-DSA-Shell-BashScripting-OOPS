p=(P1 P2 P3 P4 P5)
a=(0 1 2 3 4)
b=(3 2 4 5 6)
w=(0 0 0 0 0)
t=(0 0 0 0 0)
tm=0
o=()

total_w=0
total_t=0

while [ ${#p[@]} -gt 0 ]
do
    mbi=-1
    mb=-1
    for ((i=0; i<${#p[@]}; i++))
    do
        if [ ${a[i]} -le $tm ] && [ ${b[i]} -gt $mb ]
        then
            mb=${b[i]}
            mbi=$i
        fi
    done

    if [ $mbi -eq -1 ]
    then
        ((tm++))
        continue
    fi

    w[$mbi]=$(( $tm - ${a[mbi]} ))
    t[$mbi]=$(( ${w[mbi]} + ${b[mbi]} ))
    o+=(${p[mbi]})
    tm=$(( $tm + ${b[mbi]} ))

    echo "Process: ${p[mbi]}, Waiting time: ${w[mbi]}, Turnaround time: ${t[mbi]}"

    total_w=$((total_w + ${w[mbi]}))
    total_t=$((total_t + ${t[mbi]}))

    unset p[$mbi]
    unset a[$mbi]
    unset b[$mbi]
    p=("${p[@]}")
    a=("${a[@]}")
    b=("${b[@]}")
done

aw=$(echo "scale=2; $total_w/5" | bc)
at=$(echo "scale=2; $total_t/5" | bc)

echo "Order of processes: ${o[*]}"
echo "Average waiting time: $aw"
echo "Average turnaround time: $at"