#!/bin/bash

    echo -n "Enter first number: "
    read num1
    echo -n "Enter second number: "
    read num2
    echo "enter number 1 for addition:"
    echo "enter no. 2 for subtraction:"
    echo "enter no. 3 for division:"
    echo "enter no. 4 for multiplication"
    
    echo -n "Enter your choice:"
    read choice

    case $choice in
	    
                1)    echo "Addition Result:" $(( $num1 + $num2 ))
                     ;;
                2)    echo "Subsrtaction Result: " $(( $num1 - $num2 ))
		     ;;

		3)     echo "Division Result: " $(( $num1 / $num2 ))
		      ;;
		      
		4)  echo "multiplication Result: " $(( $num1 * $num2 ))
                      ;;
                      
		     
      esac


