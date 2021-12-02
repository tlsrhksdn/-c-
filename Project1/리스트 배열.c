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
LinkedList* concat_list(LinkedList* head1, LinkedList* head2)
{
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		LinkedList* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

int main()
{
	LinkedList* head1=NULL;
	LinkedList* head2=NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);
	
	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);
	print_list(head2);

	LinkedList* total = concat_list(head1, head2);
	print_list(total);
	return 0;
}
