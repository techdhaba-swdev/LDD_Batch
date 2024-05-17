
#--------------global variable section-----------------#

max=-1 #--max variable to store the maximum size of file fistly it get initialise to smallest number as possile in this case -1

file_count=0 #--file_count variable to store number of file present in the directory

#----------------end of global variable section---------------#




#----------------------function defination section----------------------------------#

#file_sized_count function is the main function where the max value in sized get filter and number of file get counted
file_sized_count()
{
 file_name=$1 #--file_name take the attribute pass in file_sized_count at first parameter 
	
 size_count=$(wc -c < "$file_name") #--size_count is temp local variable which store the size of file which come as attribute in function

	
 if [ "$size_count" -gt "$max" ]; #--here we checking the size of the current file in function is greater than max
 then
	
	max=$size_count #--if file sizee greater than max then we transfer the size of current file to max
	
	name="$file_name" #--here we store the file name who's size store in max
	
 fi #--end of if statement
 
	
 ((file_count+=1)) #-- here we conting the how many file is present every time when new file come we increment the file_count 
}
#--------------------------end file_sized_count() funtion---------------------------------------------------------------#


#----------------------------end of function defination section----------------------------------------------------------------#




#--------------------start of the script-------------------#

read -p "enter the from root for eg.(/home/rps/new_directory)" directory #--here we taking path of folder in directory variable as input

file_list=$(find "$directory" -type f  -name '*') #--here we getting the all value 
#echo "$file_list"

for i in $file_list;
do
        echo "$i"
	file_sized_count "$i"
done

echo "$file_count"
echo "$name"
echo "$max"


