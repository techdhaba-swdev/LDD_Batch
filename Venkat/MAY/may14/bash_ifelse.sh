#!/bin/bash

name="venkat"

echo "Enter your age :"
read age 

if [ $age -gt 18 ]; then 
	echo "hey $name your eligible for driving"
else
	echo "hey $name yourn not eligible to drive"
fi
