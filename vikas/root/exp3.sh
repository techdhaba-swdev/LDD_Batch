echo "enter n value:"
read n
echo "All even numbers upto $n"
for (( i=1; i<=n; i++ ))
do
	tmp = 'expr $i % 2'
	if[ $tmp == 0 ]
	then
		echo "$i"
	fi
done
