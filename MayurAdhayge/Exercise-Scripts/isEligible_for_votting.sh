age=0
read -p "plz enter your age:- " age
if [ "$age" -gt "17" ];
then
	echo "you are eligible for votting"
else
	echo "you are not eligible try after $(( 18 - $age )) years"
fi
