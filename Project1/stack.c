#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
#include "stack.h"

//스택 구조체 선언
typedef int element;

typedef struct{	
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 
void init_stack(StackType *s)
{
	s->top=-1;	
}
//스택 공백 상태
int is_empty(StackType *s)
{
	return (s->top==-1);
}
//스택 포화 상태
int is_full(StackType *s)
{
	return (s->top==MAX_STACK_SIZE-1);
}
//스택에 원소 삽입
void push(StackType *s,element item)
{
	if(is_full(s))
	{
		fprintf(stderr,"스택 포화 오류");
		return;
	}
	s->data[++(s->top)]=item;
}
//스택에서 원소 삭제 후 출력
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr,"스택 공백 오류");
		exit(1);
	}
	return s->data[(s->top)--];
}
//스택에서 원소를 삭제하지 않고 출력
element peek(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr,"스택 공백 오류");
		exit(1);
	}
	return s->data[s->top];
}

//동적 할당 스텍 코드
#include<stdio.h>
#include<stdlib.h>
//배열의  최대 크기를 정희하는 변수 삭제

//스택의 구조체 정의
typedef int element;

typedef struct{
	int top;
	int capacity;
	element *data;
}StackType;
//스택 초기화 함수
void init_stack(StackType *s)
{
	s->top=-1;
	s->capacity=1;
	s->data=(element*)malloc(s->capacity*sizeof(element));
}
//스택 공백상태 함수 
int is_empty(StackType*s)
{
	return s->top==-1;
}
//스택 포화상태 함수
int is_full(StackType *s)
{
	return s->top==s->capacity-1;
}
//스택 원소 삽입 함수
void push(StackType *s,element item)
{
	if(is_full(s))
	{
		s->capacity*=2;
		s->data=(element*)realloc(s->data,s->capacity*sizeof(element));
	}
	s->data[++(s->top)]=item;
}
//스택 원소 삭제함수
element peek(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr,"스택 공백 에러");
		exit(1);
	}
	return s->data[(s->top)--];
}
