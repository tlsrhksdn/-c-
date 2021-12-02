#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;
typedef struct LinkedList {
	element data;
	struct LinkedList* link;
}LinkedList;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
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
LinkedList* insert(LinkedList *head,LinkedList *pre,element value)
{
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	p->data = value;
	p->link = pre->link;
	pre->link - p;
	return head;
}
LinkedList* delete_first(LinkedList *head)
{
	LinkedList* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head=removed->link;
	free(removed);
	return head;
}
LinkedList* delete_pre(LinkedList *head,LinkedList *pre)
{
	LinkedList* removed;
	removed=pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
void print_list(LinkedList *head)
{
	for (LinkedList* p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
}
	printf("NULL\n");
}

void split(LinkedList* A_head,LinkedList*B_head,LinkedList* C_head)
{

	int cur=0;
	
	for (LinkedList* p = C_head; p != NULL; p = p->link)
	{
		if (cur % 2 == 0)
			A_head=insert_first(A_head, p->data);
		else 
			B_head=insert_first(B_head, p->data);
		cur++;
	}
	print_list(A_head);
	print_list(B_head);
}
int main()
{
	LinkedList* A_head = NULL;
	LinkedList* B_head = NULL;
	LinkedList* C_head = NULL;
	for (int i = 0; i < 5; i++)
	{
		C_head = insert_first(C_head, i);
		print_list(C_head);
	}
	split(A_head,B_head,C_head);

	return 0;
	
}
