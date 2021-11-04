#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct LinkedList {
	element data;
	struct LinkedList* link;
}LinkedList;

void print_list(LinkedList *head)
{
	LinkedList* p;
	if (head == NULL)
		return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data);
}

LinkedList* insert_first(LinkedList* head, element data)
{
	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
	node->data = data;
	if (head == NULL) {
		head = node;
		head->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}
LinkedList* insert_last(LinkedList* head, element data)
{
	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
	node->data = data;
	if (head == NULL) {
		head = node;
		head->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
int main()
{
	LinkedList* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}