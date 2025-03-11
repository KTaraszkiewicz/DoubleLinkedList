#include "doubleLinkedList.h"


int main() {
	List* list = createList();
	insertHead(list, 1);
	insertHead(list, 2);
	insertHead(list, 3);
	insertTail(list, 4);
	insertTail(list, 5);
	insertAt(list, 2, 6);
	printList(list);
	printListReverse(list);
	deleteHead(list);
	deleteAt(list, 2);
	deleteTail(list);
	printList(list);
	printListReverse(list);
	deleteList(list);
}