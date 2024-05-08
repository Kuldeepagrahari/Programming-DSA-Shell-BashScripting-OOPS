worstFit() {
	read -a memory_blocks
	read -a p_sizes
	local nm=${#memory_blocks[@]}
	local np=${#p_sizes[@]}
	echo "WORST FIT"
	for ((i=0; i<np; i++)); do
		arr1_max=0
		max_indexes=0
		for j in "${!memory_blocks[@]}"; do
	        if ((memory_blocks[j]>arr1_max)); then
	                arr1_max=${memory_blocks[j]}
	                max_indexes=$j
	        fi
		done
		if [ "${memory_blocks[max_indexes]}" -gt "${p_sizes[i]}" ]; then
    			memory_blocks[$max_indexes]=-9999999
	    		echo "$i -> $max_indexes"
	    fi
	done
}

worstFit
