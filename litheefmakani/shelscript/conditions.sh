#!/bin/bash

echo "enter your age :"
read age
if [ $age -gt 18 ]; then 
	echo "your are eligible to vote"
else 
	echo "not eligible yet"
fi 
