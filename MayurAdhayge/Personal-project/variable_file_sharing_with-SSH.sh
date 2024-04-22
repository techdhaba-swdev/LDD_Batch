fileName=""
read -p "enter the file name with extention (/home/rps/demo.txt):- " fileName
sshpass -p 'rps@12345' ssh  rps@172.20.0.51
cd ~ 
if [ -e MayurTransferFiles];
then
	echo "filepresent"
else
  mkdir MayurTransferFiles
fi
ls -l MayurTransferFiles
exit
#Scp -p 'rps@12345' fileName rps@172.20.0.51:/home/rps/MayurTransferFiles/
