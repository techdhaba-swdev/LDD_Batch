#!/bin/bash

# Function to count lines in a file
files=("task2.sh" "task5.sh" "program.c")
for ((i =0; i <=4; i ;ooi++))
do
	echo "number of lines in file ${files[i]} is $(wc -l ${files[i]})";
done
