
word_count()
{
	file_name=$1
	echo "$(wc -l $file_name)"
}

file_list=$(ls)
#echo "$file_list"
for i in $file_list;
do
	word_count "$i"
done
