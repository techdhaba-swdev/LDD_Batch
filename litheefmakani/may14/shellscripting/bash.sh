#!/bin/bash

echo "enter your name:"
read name

echo "enter your age:"
read age

if [ $age -gt 18]; then 
	echo "hi $name you are a major."
else 
	echo "hi $name you are not eligible."
fi

