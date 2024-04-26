echo "enter n value:"
read n
echo "enter array values:"
for((i=1;i<=n;i++))
do
	read a[i];
done
echo "the array elements are:"
for((i=1;i<=n;i++))
do
	echo "${a[i]}"
done

