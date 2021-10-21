#include<stdio.h>
#include<stdlib.h>

//����Ʈ ���� 
typedef int element;

typedef struct LinkedList {
	element data;
	struct LinkedList *link;
}LinkedList;
//���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//ù ���� ���� ����Ʈ ����
LinkedList*insert_first(LinkedList *head, element value)
{
	LinkedList *p = (LinkedList*)malloc(sizeof(LinkedList));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
//��� �ڿ� ���ο� ��� ����
LinkedList *insert(LinkedList *head, LinkedList*pre, element value)
{
	LinkedList *p = (LinkedList*)malloc(sizeof(LinkedList));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

//ù��° ��� ����
LinkedList *delete_first(LinkedList *head)
{
	LinkedList *removed;
	if (head == NULL) return NULL;
	removed = head; //??
	head = removed->link;
	free(removed);
	return head;
}

//����Ʈ�� ����Ű�� ���� ����Ʈ�� ��� ����
LinkedList *delete(LinkedList *head, LinkedList *pre)
{
	LinkedList *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
//����Ʈ ���
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