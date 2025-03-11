CC = gcc
CFLAGS = -Wall -Wpedantic

all: list_test

list_test: list_test.o doubleLinkedList.o
	$(CC) $(CFLAGS) -o list_test list_test.o doubleLinkedList.o

list_test.o: list_test.c doubleLinkedList.h
	$(CC) $(CFLAGS) -c -g list_test.c

doubleLinkedList.o: doubleLinkedList.c doubleLinkedList.h
	$(CC) $(CFLAGS) -c -g doubleLinkedList.c

clean:
	rm -f *.o list_test
