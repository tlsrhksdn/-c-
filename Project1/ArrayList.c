#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100
typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//����Ʈ �ʱ�ȭ
void init_list(ArrayListType *L)
{
	L->size == 0;
}

//����Ʈ ���鼳��
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}
//����Ʈ ��ȭ����
int is_full(ArrayListType *L)
{
	return L -> size >= MAX_LIST_SIZE;
}
//Ư�� ��ġ�� ����Ʈ ���� ��ȯ
element peek(ArrayListType *L,int pos)
{
	if (pos<0 || pos>L->size)
		error("��ġ ����");
	return L->array[pos];
}
//����Ʈ ���
void print_list(ArrayListType *L)
{
	for (int i = 0; i < L ->size; i++)
	{
		printf("%d->", L->array[i]);
	}
	printf("\n");
}
//������ ��ġ�� ���� ����
void insert_last(ArrayListType *L, element item)
{
	if (is_full(L))
		error("����Ʈ �����÷ο�");
	L->array[(L->size)++] = item;
}
//������ ��ġ�� ���� ����
void insert(ArrayListType *L, int pos, element item)
{
	if((pos>=0)&&(pos<=L->size)&&(!is_full(L)))
		for (int i= (L->size-1);i>=pos;i--)
		{
			L->array[i+1]=L->array[i];
		}
	L->array[pos]=item;
	L->size++;

}
//Ư�� ��ġ�� ���� ����
element delete(ArrayListType *L, int pos)
{
	element temp=L->array[pos];
	if ((pos >= 0) && (pos <= L->size) && (!is_full(L)))
	{
		for (int i = pos; i < (L->size-1); i++)
		{
			L->array[i] = L->array[i + 1];
		}
		L->size--;
	}
	return item;
}


