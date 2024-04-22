num=10
if [ $num -gt 1000 ]
then
	echo "Thats huge number"
elif [ $num -gt 100 ]
then
	echo "thats a big number"
else
	echo "thats small number"
fi
