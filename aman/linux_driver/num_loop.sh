#!/bin/bash

for ((i=1; i <= 20; i++)); do
	echo $i
	if ((i > 10)); then
		echo "I'm big!"
	fi
done

