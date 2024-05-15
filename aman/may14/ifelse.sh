#!/bin/bash

num=10
message=""
if [ $num -gt 10 ]; then
	message="the number is greater than 10."
elif [ $num -eq 10 ]; then
	message="the number is equal to 10."
else
	message="the number is less than 10."
fi
echo $message
