CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o doubleLinkedList.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c doubleLinkedList.h
	$(CC) $(CFLAGS) -c main.c

doubleLinkedList.o: doubleLinkedList.c doubleLinkedList.h
	$(CC) $(CFLAGS) -c doubleLinkedList.c

clean:
	rm -f $(OBJ) $(TARGET)
