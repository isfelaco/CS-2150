#!/bin/bash

# Isabella Felaco, isf4rjk
# 3-15-22
# averagetime.sh

# prompts the user for the dictionary and grid file names
# runs the program five times using those parameters
# records the time of each execution run
# prints the average run time



cd </mnt/c/Users/isfel/OneDrive\ -\ University\ of\ Virginia/Second\ Year/CS\ 2150/lab7>/
#make


echo "Enter the number of iterations:"
read input1
itr=${input1}
echo

quit=quit
total_time=0

if [[ ${itr} == ${quit} ]]; then
	exit 1
else
	for i in {1,2,3,4,5}; do
		echo "Running iteration $i..."
		RUNNING_TIME=`./a.out $itr | tail -1`
		echo ${RUNNING_TIME}
		(( total_time+=RUNNING_TIME ))
	done
fi

echo "5 iterations took $total_time ms"
average_time=$((($total_time)/5))
echo "Average time was $average_time ms"