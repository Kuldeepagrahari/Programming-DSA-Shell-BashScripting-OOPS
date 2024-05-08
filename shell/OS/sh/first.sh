#!/bin/bash

firstFit() {
	read -a memory_blocks
	read -a p_sizes
	local nm=${#memory_blocks[@]}
	local np=${#p_sizes[@]}
	echo "FIRST FIT"
	for ((i=0; i<np; i++)); do
		for((j=0; j<nm; j++)); do
			if [ "${memory_blocks[j]}" -gt "${p_sizes[i]}" ]; then
    			memory_blocks[$j]=-9999999
	    		echo "$i -> $j"
	    		break
	    	fi
		done
	done
}
firstFit
