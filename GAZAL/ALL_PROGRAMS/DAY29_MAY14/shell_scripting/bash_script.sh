#!/bin/bash

# Declare variables
string="welcome!"
integer=2

# Check the value of the integer
if [ $integer -gt 5 ]; then
    echo "$string The integer is greater than 5."
else
    echo "$string The integer is not greater than 5."
fi
