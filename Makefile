CC = gcc
CFLAGS = -Wall -Wpedantic

all: list_test lib_test.out lib_test_bibDyn.out

lib_test_bibDyn.out: doubleLinkedList.c doubleLinkedList.h list_test.c
	$(CC) -c $(CFLAGS) -fPIC -D_GNU_SOURCE doubleLinkedList.c -o doubleLinkedListDyn.o
	$(CC) doubleLinkedListDyn.o -shared -o lib_listDyn.so
	$(CC) -c list_test.c -o list_testDyn.o
	$(CC) list_testDyn.o -L. -l_listDyn -o lib_test_bibDyn.out

lib_test.out: lib_list_static.a list_test.o
	$(CC) $(CFLAGS) list_test.o lib_list_static.a -o lib_test.out

lib_list_static.a: doubleLinkedList.o
	ar r lib_list_static.a doubleLinkedList.o

list_test: list_test.o doubleLinkedList.o
	$(CC) $(CFLAGS) -o list_test list_test.o doubleLinkedList.o

list_test.o: list_test.c doubleLinkedList.h
	$(CC) $(CFLAGS) -c -g list_test.c

doubleLinkedList.o: doubleLinkedList.c doubleLinkedList.h
	$(CC) $(CFLAGS) -c -g doubleLinkedList.c

clean:
	rm -f *.o list_test
	rm -f *.a
	rm -f *.out
	rm -f *.so
