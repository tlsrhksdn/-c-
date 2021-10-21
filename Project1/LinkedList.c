#include<stdio.h>
#include<stdlib.h>

//리스트 정의 
typedef int element;

typedef struct LinkedList {
	element data;
	struct LinkedList *link;
}LinkedList;
//오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//첫 번쨰 노드로 리스트 삽입
LinkedList*insert_first(LinkedList *head, element value)
{
	LinkedList *p = (LinkedList*)malloc(sizeof(LinkedList));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
//노드 뒤에 새로운 노드 삽입
LinkedList *insert(LinkedList *head, LinkedList*pre, element value)
{
	LinkedList *p = (LinkedList*)malloc(sizeof(LinkedList));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

//첫번째 노드 제거
LinkedList *delete_first(LinkedList *head)
{
	LinkedList *removed;
	if (head == NULL) return NULL;
	removed = head; //??
	head = removed->link;
	free(removed);
	return head;
}

//리스트가 가리키는 다음 리스트의 노드 제거
LinkedList *delete(LinkedList *head, LinkedList *pre)
{
	LinkedList *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
//리스트 출력
void print_list(LinkedList *head)
{
	for (LinkedList *p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL \n");
}
int main()
{
	LinkedList *head = NULL;

	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}
}