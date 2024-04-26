echo "listing files using ls"
ls
echo "using cat to display content"
cat exp1.sh
echo "using touch to create empty files"
touch f.txt
ls
echo "copying from one file to another"
cp a.txt f.txt
cat f.txt
echo "renaming the file"
mv f.txt f1.txt
ls
echo "removing the file"
rm f1.txt
ls
