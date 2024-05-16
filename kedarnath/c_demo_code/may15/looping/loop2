#!/bin/bash 

for FILE in *.txt; 
do
	echo $FILE 
	i=0
	while read line;
	do
		echo $line
	done < $FILE
	count= $( stat -c %s $FILE ) 
       echo $count 	
done

