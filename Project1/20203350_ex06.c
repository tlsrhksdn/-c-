#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct DLinkedList {
	element data;
	struct DLinkedList* llink;
	struct DLinkedList* rlink;
}DLinkedList;

void init(DLinkedList* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}
void print_dlist(DLinkedList* phead)
{
	DLinkedList* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("<-| |%d| |->", p->data);
	}
	printf("\n");
}
void print_reverse(DLinkedList* phead)
{
	DLinkedList* p;
	printf("�����͸� �������� ���: ");
	for ( p = phead->llink; p != phead; p = p->llink)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}
void dinsert(DLinkedList* before, element data)
{
	DLinkedList* newnode = (DLinkedList*)malloc(sizeof(DLinkedList));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
void dinsert_last(DLinkedList* before, element data)
{
	DLinkedList* newnode = (DLinkedList*)malloc(sizeof(DLinkedList));
	newnode->data = data;
	newnode->rlink = before;
	newnode->llink = before->llink;
	before->llink->rlink = newnode;
	before->llink = newnode;
}


void ddelete(DLinkedList* head, DLinkedList* removed)
{
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
int main()
{
	DLinkedList* head = (DLinkedList*)malloc(sizeof(DLinkedList));
	init(head);

	int n, x;
	printf("�������� ������ �Է��ϼ��� : ");
	scanf_s("%d", &n,sizeof(n));
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		printf("��� # % d�� �����͸� �Է��Ͻÿ� : ", i);
		scanf_s("%d", &x,sizeof(x));
		dinsert_last(head, x);
	}
	printf("\n");
	print_reverse(head);

	free(head);
	return 0;
}