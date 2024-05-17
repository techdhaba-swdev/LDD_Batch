#!/bin/bash

string="Hello World!"
my_integer=26

if [[ $my_integer -gt 24 ]] ;then
	echo "the integer is greater than 24."
else
	echo "the integer is not greater than 24."
fi

echo "String value is: $string"
