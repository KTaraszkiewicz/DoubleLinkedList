#include <stddef.h>
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct Node Node;
typedef struct DoubleLinkedList List;

List* createList();
void deleteList(List* list);
void insertTail(List* list, int data);
void insertHead(List* list, int data);
void insertAt(List* list, int index, int data);
void deleteHead(List* list);
void deleteTail(List* list);
void deleteAt(List* list, int index);
int isEmpty(List* list);
int getSize(List* list);
void printList(List* list);
void printListReverse(List* list);
#endif