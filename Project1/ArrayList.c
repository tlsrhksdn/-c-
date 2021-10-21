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
//리스트 초기화
void init_list(ArrayListType *L)
{
	L->size == 0;
}

//리스트 공백설정
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}
//리스트 포화설정
int is_full(ArrayListType *L)
{
	return L -> size >= MAX_LIST_SIZE;
}
//특정 위치의 리스트 원소 반환
element peek(ArrayListType *L,int pos)
{
	if (pos<0 || pos>L->size)
		error("위치 오류");
	return L->array[pos];
}
//리스트 출력
void print_list(ArrayListType *L)
{
	for (int i = 0; i < L ->size; i++)
	{
		printf("%d->", L->array[i]);
	}
	printf("\n");
}
//마지막 위치에 원소 삽입
void insert_last(ArrayListType *L, element item)
{
	if (is_full(L))
		error("리스트 오버플로우");
	L->array[(L->size)++] = item;
}
//임의의 위치에 원소 삽입
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
//특정 위치의 원소 제거
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


