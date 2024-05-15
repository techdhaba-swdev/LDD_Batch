#!/bin/bash
find_occurance() {
	word=$1
	file=$2
	grep -o -w "$word" "$file" | sort
}
find_occurance "program" "sample.txt"
