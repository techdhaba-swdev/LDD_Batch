command
if [ $? -eq 0 ];
then 
	echo " command exexuted successfully"
else
	echo "command failed with exit status:$?."
fi
