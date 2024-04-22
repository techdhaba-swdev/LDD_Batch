#!/usr/bin/env bash
num=101
if [ $num -gt 1000 ]
then
	echo $ "number is huge"
elif	 [ $num -gt 100 ]
then
	echo "that is a big num"
else
	echo "that's a small number."
fi
