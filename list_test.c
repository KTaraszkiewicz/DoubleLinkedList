#include "doubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void Menu() {
	printf("1. Insert Head\n");
	printf("2. Insert Tail\n");
	printf("3. Insert At\n");
	printf("4. Delete Head\n");
	printf("5. Delete Tail\n");
	printf("6. Delete At\n");
	printf("7. Print List\n");
	printf("8. Print List Reverse\n");
	printf("9. Delete List\n");
	printf("10. Exit\n");
}

void choose_option(List* list, int option) {
	int data, pos;
	switch (option) {
	case 1:
		printf("Enter data: ");
		scanf("%d", &data);
		insertHead(list, data);
		break;
	case 2:
		printf("Enter data: ");
		scanf("%d", &data);
		insertTail(list, data);
		break;
	case 3:
		printf("Enter data: ");
		scanf("%d", &data);
		printf("Enter position: ");
		scanf("%d", &pos);
		insertAt(list, pos, data);
		break;
	case 4:
		deleteHead(list);
		break;
	case 5:
		deleteTail(list);
		break;
	case 6:
		printf("Enter position: ");
		scanf("%d", &pos);
		deleteAt(list, pos);
		break;
	case 7:
		printList(list);
		break;
	case 8:
		printListReverse(list);
		break;
	case 9:
		deleteList(list);
		break;
	case 10:
		exit(0);
		break;
	default:
		printf("Invalid option\n");
		break;
	}
}

void enter_option() {
	List* list = createList();
	int option;
	while (1) {
		Menu();
		printf("Enter option: ");
		scanf("%d", &option);
		choose_option(list, option);
	}
}


int main() {
	enter_option();
	return 0;
}