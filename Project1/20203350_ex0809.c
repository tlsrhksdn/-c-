//프로그램 4.5
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element *data;
	int capacity;
	int top;
}StackType;


int is_empty(StackType *s)
{
	return (s->top == -1);
}
int is_full(StackType *s)
{
	return (s->top == (s->capacity - 1));
}
void push(StackType *s, element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;

}
element pop(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

//이하코드동일
void init_stack(StackType *s)
{
	s->top = -1;
	s->capacity = 10;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}
int main(void)
{
	StackType s;
	init_stack(&s);
	for (int i = 0; i < 20; i++)
	{
		push(&s, i);
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", pop(&s));
	}
	free(s.data);
	return 0;
}

//8번문제
