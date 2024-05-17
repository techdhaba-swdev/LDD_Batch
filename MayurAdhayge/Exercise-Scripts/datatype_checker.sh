#!/bin/bash

str_value="example string"
declare -i int_value="10"

first=$(declare -p str_value)
second=$(declare -p int_value)
echo "$first $second"
