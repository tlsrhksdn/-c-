#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct LinkedList {
	element data;
	struct LinkedList* link;
}LinkedList;

LinkedList* insert_first(LinkedList* head, element value)
{
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(LinkedList* head)
{
	for (LinkedList* p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL \n");
}
LinkedList* search_list(LinkedList* head, element value)
{
	LinkedList* p = head;

	while (p != NULL)
	{
		if (p->data == value)
			return p;
		p = p->link;
	}
	return NULL;
}
int main()
{
	LinkedList* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	if (search_list(head, 30) != NULL)
		printf("리스트에서 30을 찾았습니다.\n");
	else
		printf("리스트에서 30을 찾지 못했습니다. \n");
	return 0;
}