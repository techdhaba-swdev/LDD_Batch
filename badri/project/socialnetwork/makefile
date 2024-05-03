CC = gcc
CFLAGS = -I.
DEPS = profile.h header.h
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $ < $(CFLAGS)

social : userprofile.c addfriend.c searchuser.c display.c free.c main.c
	$(CC) -o  social userprofile.c addfriend.c searchuser.c display.c free.c main.c
