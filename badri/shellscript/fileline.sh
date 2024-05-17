#! /bin/bash

echo Enter the filename
read file
l=grep-c"." $file
echo Number of lines in $file is $l
