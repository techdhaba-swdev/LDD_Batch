CC = gcc

CFLAGS = -I.

DEPS = UserNode.h User.h UserProfile.h SearchUsersByName.h Graph.h DisplayFriends.h CreateUserProfile.h AddFriend.h

OBJ =  AddFriend.o CreateUserProfile.o DisplayFriends.o SearchUsersByName.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

