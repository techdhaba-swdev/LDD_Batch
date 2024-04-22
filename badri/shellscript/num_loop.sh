#!/usr/bin/env bash
for n in {1..20}
do
	echo $n
	if [ $n -gt 10 ]
	then 
		echo "I'm big!"
	fi
done
