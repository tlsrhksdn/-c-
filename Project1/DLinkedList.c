#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DLinkedList {
	element data;
	struct DLinkedList* llink; //리스트의 왼족 링크
	struct DLinkedList* rlink; //리스트의 오른쪽 링크
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
void dinsert(DLinkedList* before, element data)
{
	DLinkedList* newnode = (DLinkedList*)malloc(sizeof(DLinkedList));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
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
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++)
	{
		dinsert(head, i);
		print_dlist(head);
	}
	printf("삭제 단계\n");
	for (int i = 0; i < 5; i++)
	{
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}