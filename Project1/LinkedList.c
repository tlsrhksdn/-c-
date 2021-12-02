#include<stdio.h>
#include<stdlib.h>
//연결리스트 구조체
typedef int element;
typedef struct{
	element data;
	struct LinkedList *link;
}LinkedList;
//에러 메시지 출력함수
void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
//첫 번째 리스트에 원소 삽입함수(암기!)
LinkedList* insert_first(LinkedList *head,element item)
{
	LinkedList *p=(LinkedList*)malloc(sizeof(LinkedList));
	p->data=item;
	p->link=head;
	head=p;
	return head;
}
//특정 위치에 원소 삽입함수
LinkedList* insert(LinkedList *head,LinkedList *pre,element item)
{
	LinkedList* p=(LinkedList*)malloc(sizeof(LinkedList));
	p->data=item;
	p->link=pre->link;
	pre->link=p;
	return head;
}
//첫 번째 위치에 원소 삭제함수
LinkedList* delete_first(LinkedList *head)
{
	LinkedList*removed;
	if(head==NULL) return NULL;
	removed->link=head;
	head=removed;
	free(removed);
	return head;
}
//특정 위치에 원소 삭제함수
LinkedList* delete(LinkedList *head,LinkedList* pre)
{
	LinkedList *removed;
	removed=pre->link;
	pre->link=removed->link;
	free(removed);
	return head;	
}
//연결리스트 출력함수
void print_list(LinkedList *head)
{
	for(LinkedList*p=head;p!=NULL;p=p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL");
}
//리스트 원소 출력
