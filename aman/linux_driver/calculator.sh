#!/bin/bash

add(){
	echo $(($1+$2))
}
substract(){
	echo $(($1-$2))
}
multiply(){
	echo $(($1*$2))
}
divide(){
	echo $(($1/$2))
}

echo "simple calculator"
echo "enter 1st number:"
read number1
echo "enter 2nd number:"
read number2
echo "select operation: +,-,*,/"
read operation

case $operation in
	+)
		result=$(add $number1 $number2)
		;;
	-)
		result=$(substract $number1 $number2)
		;;
	*)
		result=$(multiply $number1 $number2)
		;;
	/)
		echo "Invalid Operation"
		exit 1
		;;
esac

echo "Result: $result"
