heloMake:heloMake.o heloDef.o
	gcc -o heloMake heloMake.o heloDef.o -I.
	
heloMake.o: heloMake.c
	gcc -c -o heloMake.o heloMake.c -I.
	
heloDef.o: heloDef.c
	gcc -c -o heloDef.o heloDef.c -I.

.PHONY: clear
clear:
	rm -f heloMake *.o 

