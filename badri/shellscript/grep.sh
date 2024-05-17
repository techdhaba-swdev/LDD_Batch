#!/usr/bin/env /bash
word='l'
file="grep.txt"
grep -o -i "$word" "$file" | sort
