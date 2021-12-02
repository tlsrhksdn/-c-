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
	printf("NULL\n");
}
LinkedList* reverse(LinkedList* head)
{
	LinkedList *p, *q, *r;

	p = head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}
int main()
{
	LinkedList* head1 = NULL;
	LinkedList* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);

	head2 = reverse(head1);
	print_list(head2);

	return 0;
}