#!/usr/bin/bash
word="int"
file="main.c"
grep   "$word" "$file" | sort
