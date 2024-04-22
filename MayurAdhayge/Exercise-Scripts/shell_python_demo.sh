rm -rf demoPy.py
touch demoPy.py
echo '
import random as rd
print("*"*100)
while True: 
 print("*"*100)
 rn=rd.randint(1,5)
 num =input("\t\t\tguess the number between 1-05:-  ")
 if len(num) == 0 or int(num) < 1 or  int(num) > 5:
    print("\n\t\t\t\tplz,enter valid number!!\n")
    continue;
 num=int(num) 
 print("\n\t\t\t\tlotery number is ",rn)
 if rn==num:
       print("\n\t\t\tcongratulation ,you won the bumper price !!!")
       print("\n\n\t\t\t\tlucky number :-  ",rn)
       print("\n\n\t\t\t\tnow you can leave")
       break;
 else:
       print("\n\t\t\t\ttry your luck next time...")
' > demoPy.py
python3 demoPy.py

