touch demo.txt
echo "this is file created by the the automated script and the file delete automaticaly " > demo.txt
mv demo.txt demoCpy.txt
echo "demoCpy.txt contents:-"
cat demoCpy.txt
echo "some etra data edited" >> demoCpy.txt
cat demoCpy.txt
rm demoCpy.txt


