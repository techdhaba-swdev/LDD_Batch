#!/usr/bin/env bash

num=101
if [ $num -gt 1000 ]
then
	echo "that'a a huge number!"
elif [ $num -gt 100 ]
then
	echo "that's a big number!"
else
	echo "that's a small number."
fi
