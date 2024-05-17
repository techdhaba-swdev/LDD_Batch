#!/bin/bash

word="Hello"
filename="text1.txt"


# Find occurrences of the specified word
grep -o "$word" "$filename" | sort
