#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100
//리스트 구조체 생성
typedef int element;

typedef struct{
	element array[MAX_LIST_SIZE];
	int size;
}ArrayLIst;
//에러 메시지 출력함수
void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
//리스트 초기화 함수
void init_list(ArrayLIst *L)
{
	L->size=0;
}
//리스트 공백상태 함수
int is_empty(ArrayLIst *L)
{
	return L->size==0;
}
//리스트 포화상태 함수
int is_full(ArrayLIst *L)
{
	return L->size==MAX_LIST_SIZE;
}
//리스트 원소 삭제하지 않고 반환함수
element get_entry(ArrayLIst *L,int pos)
{
	if(pos<0 || pos>L->size)
	error("위치 오류");
	return L->array[pos];
}
//리스트 전체원소 출력함수
void print_list(ArrayLIst *L)
{
	for(int i=0;i<L->size;i++)
	{
		printf("%d->",L->array[i]);
	}
}
//리스트 마지막위치에 원소 삽입함수
void insert_last(ArrayLIst *L,element item)
{
	if(is_full(L))
	error("리스트 오버플로우");
	L->array[(L->size)++]=item;
}
//리스트 특정위치에 원소 삽입함수
void insert(ArrayLIst *L,int pos,element item)
{
	if(is_full(L))
	error("리스트 오버플로우");
	for(int i=(L->size-1);i>=pos;i--)
	{
		L->array[i+1]=L->array[i];
	}
	L->array[pos]=item;
	L->size++;
}
//리스트 특정위치 원소 삭제함수
element delete(ArrayLIst*L,int pos)
{
	element item=L->array[pos];
	if(pos<0 || pos>L->size)
	error("공백 오류");
	for(int i=pos;i<=(L->size-1);i++)
	{
		L->array[i]=L->array[i+1];
	}
	L->size--;
	return item;

}
//리스트 모든요소 삭제함수
void clear_list(ArrayLIst *L)
{
	for(int i=0;i<=L->size;i++)
	{
		L->array[i]=NULL;
	}
}
//리스트 특정위치 원소 반환함수
element peek(ArrayLIst *L,int pos)
{
	return L->array[pos];
}


