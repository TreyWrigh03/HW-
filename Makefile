
CC = g++
CFLAGS = -g -Wall -Wextra

default: phonebook

phonebook: Phonebook.o main.o
	$(CC) $(CFlags) -o test Phonebook.o main.o

Phonebook.o: Phonebook.cpp Phonebook.h
	$(CC) $(CFLAGS) -c Phonebook.cpp

main.o:	main.cpp Phonebook.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) phonebook *.o *~
