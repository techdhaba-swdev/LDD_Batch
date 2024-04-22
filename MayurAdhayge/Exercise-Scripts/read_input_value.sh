
name=""
while [ "$name" != "exit" ] && [ "$name" != "Exit" ];
do
echo "************************************************************************************************************************************"
read -p "enter your name:- " name
if [ "$name" != "" ] && [ "$name" != "exit" ] && [ "$name" != "Exit" ];
then
   echo "hello, $name"
   read -p "if want to exit type exit :" name
else
   name=""
   echo "plz give valid name "
   continue
fi
done
