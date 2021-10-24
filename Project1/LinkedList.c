#include<stdio.h>
#include<stdlib.h>

//연결리스트 출력함수
typedef int element;
typedef LinkedList{
	element data;
	struct Linkedlist *link;
}LinkedList;
//에러 메시지 출력함수
void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
//첫 번째 리스트에 원소 삽입함수
void insert_first(LinkedList *head,int value)
{
	LinkedList *p=(LinkedList*)malloc(sizeof(LinkedList));
	p->data=value;
	p->link=head;
	head=p;
	return head;
}
//특정 위치에 원소 삽입함수
void insert(LinkedList *head,LinkedList *pre,int value)
{
	LinkedList *p=(LinkedList*)malloc(sizeof(LinkedList));
	p->data=value;
	p->link=pre->link;
	pre->link=p;
	return head;
}
//첫 번째 위치에 원소 삭제함수
element delete_first(LinkedList *head)
{

}
//특정 위치에 원소 삭제함수

//리스트 원소 출력
