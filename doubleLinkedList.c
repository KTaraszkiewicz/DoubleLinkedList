#include "doubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>



struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct DoubleLinkedList {
	struct Node* head;
	struct Node* tail;
	int size;
};

List* createList() {
	List* list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void deleteList(List* list) {
	Node* current = list->head;
	while (current != NULL) {
		Node* next = current->next;
		free(current);
		current = next;
	}
	free(list);
}

void insertTail(List* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = list->tail;
	if (list->tail != NULL) {
		list->tail->next = newNode;
	}
	list->tail = newNode;
	if (list->head == NULL) {
		list->head = newNode;
	}
	list->size++;
}

void insertHead(List* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->head;
	newNode->prev = NULL;
	if (list->head != NULL) {
		list->head->prev = newNode;
	}
	list->head = newNode;
	if (list->tail == NULL) {
		list->tail = newNode;
	}
	list->size++;
}

void insertAt(List* list, int index, int data) {
	if (index < 0 || index > list->size) {
		printf("Index out of bounds\n");
		return;
	}
	if (index == 0) {
		insertHead(list, data);
		return;
	}
	if (index == list->size) {
		insertTail(list, data);
		return;
	}
	Node* current = list->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = current;
	newNode->prev = current->prev;
	current->prev->next = newNode;
	current->prev = newNode;
	list->size++;
}

void deleteHead(List* list) {
	if (list->head == NULL) {
		printf("List is empty\n");
		return;
	}
	Node* temp = list->head;
	list->head = list->head->next;
	if (list->head != NULL) {
		list->head->prev = NULL;
	}
	free(temp);
	list->size--;
}

void deleteTail(List* list) {
	if (list->tail == NULL) {
		printf("List is empty\n");
		return;
	}
	Node* temp = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	free(temp);
	list->size--;
}

void deleteAt(List* list, int index) {
	if (index < 0 || index >= list->size) {
		printf("Index out of bounds\n");
		return;
	}
	if (index == 0) {
		deleteHead(list);
		return;
	}
	if (index == list->size - 1) {
		deleteTail(list);
		return;
	}
	Node* current = list->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
	list->size--;
}

int isEmpty(List* list) {
	if (list->size == 0) {
		return 1;
	}
	return 0;
}

int getSize(List* list) {
	return list->size;
}

void printList(List* list) {
	Node* current = list->head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void printListReverse(List* list) {
	Node* current = list->tail;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->prev;
	}
	printf("\n");
}
