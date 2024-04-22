checkfile= "/home/rps/Desktop/file_exist.txt"
targetfolder= "/home/rps/Desktop/Demo/folder.txt"

if [ -f "$checkfile" ] ;
then
	echo "file exist"
else
	echo " file does not exist copy to target folder"
	cp "$checkfile" "$targetfolder"
fi

