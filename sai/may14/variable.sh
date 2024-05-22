#!/bin/bash
num=5
my_string="hello world welcome my team"
my_integer=50

if [ $my_integer -gt ${#my_string} ]
then
	echo "The integer is greater than 10"
else
	echo "The integer is less than or equal to 20"
fi
