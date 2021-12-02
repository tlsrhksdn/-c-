#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}LinkedList;

void error(char* message)
{
	fprintf(stderr, "s\n", message);
	exit(1);
}
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
		printf("%s->", p = p->data.name);
	}
	printf("NULL \n");
}
int main()
{
	LinkedList* head = NULL;
	element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}