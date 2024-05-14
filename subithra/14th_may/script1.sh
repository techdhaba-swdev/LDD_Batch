#!/bin/bash

# Task 3: Bash script with if-else statement

# Declaring variables
string_v="Hii, this is subi!"
integer_v=10

# If-else statement
if [ $integer_v -gt 5 ]; then
    echo "$string_v The integer $integer_v is greater than 5."
else
    echo "$string_v The integer $integer_v is not greater than 5."
fi
