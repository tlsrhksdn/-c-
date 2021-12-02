#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char element[100];

typedef struct LinkedList {
	element data;
	struct LinkedList* link;
}LinkedList;

LinkedList* insert_first(LinkedList* head, element data)
{
	LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
	strcpy(node->data, data);
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}
int main()
{
	LinkedList* head = NULL;

	head = insert_first(head, "KIM");
	head = insert_first(head, "PARK");
	head = insert_first(head, "CHOI");

	LinkedList* p = head;
	for (int i = 0; i < 10; i++) {
		printf("ÇöÀç Â÷·Ê=%s\n", p->data);
		p = p->link;
	}
	return 0;
}
