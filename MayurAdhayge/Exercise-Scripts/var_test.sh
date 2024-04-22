num1=12
num2=10
echo "Arithmatic opration on two number num1= $num1 and num2= $num2"
echo "************************************************************************"
echo "Addition of two number"
echo " $num1+$num2=$(( $num1 + $num2 ))"
echo "substraction of two number"
echo  " $num1-$num2=$(( $num1 - $num2 ))"
echo "Multiplication of two number"
echo  " $num1*$num2=$(( $num1 * $num2 ))"
echo "Division of two number"
echo  " $num1/$num2=$( (bc <<< "scale=2; $num1 / $num2") )"

