fileName=""
path=""
flag=''
while true;
do
echo "**********************************************************************************************************************"
echo
echo "                                          file checker in directory"
echo
read -p "plz,the directory in which you want to check ( /home/rps/dirctory) :- " path
echo
read -p "plz enter the file name :- " fileName
searchVal="$path/$fileName"


if [ -e "$searchVal" ]; 
then
      echo
      echo "                                  file directory exits ! ! ! "
      echo "                                 this is valid path = $searchVal"
else
     echo
     echo "                                sorry ! ! !  file directory not exits"
fi 
echo
echo "**********************************************************************************************************************"
read -p "do you want check other directory or end the program (y/n)? :- " flag
if [ "$flag" == 'n' ] || [ "$flag" == 'N' ];
then
	break
fi
done
