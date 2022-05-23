#!/bin/bash

# Isabella Felaco, isf4rjk
# 3-15-22
# averagetime.sh

# prompts the user for the dictionary and grid file names
# runs the program five times using those parameters
# records the time of each execution run
# prints the average run time


cd </mnt/c/Users/isfel/OneDrive\ -\ University\ of\ Virginia/Second\ Year/CS\ 2150/lab6>/

echo "Enter the name of your grid file (excluding .txt):"
read input1
gridname=${input1}.txt
echo

echo "Enter the name of your dictionary file (excluding .txt):"
read input2
dictname=${input2}.txt
echo

./a.out ${dictname} ${gridname} > output.txt
t1=`tail -1 output.txt`

./a.out ${dictname} ${gridname} > output.txt
t2=`tail -1 output.txt`

./a.out ${dictname} ${gridname} > output.txt
t3="$( echo `tail -1 output.txt` |bc)"

./a.out ${dictname} ${gridname} > output.txt
t4="$( echo `tail -1 output.txt` |bc)"

./a.out ${dictname} ${gridname} > output.txt
t5="$( echo `tail -1 output.txt` |bc)"


time="$(echo $t1+$t2+$t3+$t4+$t5 |bc)"
echo "$(echo $time/5|bc)" milliseconds