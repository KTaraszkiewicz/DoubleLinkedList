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
int isEmpty(List* list);

#endif