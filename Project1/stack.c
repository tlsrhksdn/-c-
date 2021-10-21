//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 100
//#include "stack.h"
//
//void init_stack(StackType *s)
//{
//	s->top = -1;
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}

#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct {
	element *data;
	int top;
	int capacity;
}StackType;

void init_stack(StackType *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}
int is_empty(StackType *s)
{
	return s->top == -1;
}
int is_full(StackType *s)
{
	return s->top == s->capacity-1;
}
void push(StackType *s,element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

