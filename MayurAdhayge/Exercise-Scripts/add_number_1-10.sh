echo
echo
echo ************this is mayur scripts**********************
echo
echo  now we write the number 1 to 10
sum=0
for i in `seq 1 10`
do
echo $i
sum=`expr $sum + $i`
done
echo
echo sum of the 10 number is $sum
