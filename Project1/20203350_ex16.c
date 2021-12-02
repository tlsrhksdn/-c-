#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s) 
{
	s->top = -1;
}
int is_empty(StackType *s)
{
	return (s->top == -1);
}
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType *s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화상태입니다.\n");
		return;
	}
	else
		item = s->data[++(s -> top)];
	
}
element pop(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백상태입니다.\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
element peek(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백상태입니다.\n");
		exit(1);
	}
	else
		return s->data[(s->top)];
}


void main()
{
	char line[100];
	StackType *s;

	init_stack(&s);
	printf("문자열을 입력하시오 : ");
	gets_s(line, sizeof(line));

	for (int i = 0; i < strlen(line) / 2; i++)
		push(&s, line[i]);
	for (int i = (strlen(line) / 2)+1; i < strlen(line); i++)
	{
		if (pop(&s) != line[i])
		{
			printf("회문이 아닙니다.\n");
			return;
		}
	}	

	if (check_palindrome(&s, line) == 1)
	{
		printf("회문입니다.\n");
		return;
	}
	else
		printf("회문이 아닙니다.\n");
	return;
}

int check_palindrome(StackType *s, element exp[])
{
	int i = 0, len = strlen(exp);
	printf("문자열을 입력하시오 : ");
	for (int i = 0; i < len; i++)
	{
		if (exp[i] >= 'A'&&exp[i] <= 'Z')
		{
			push(s, tolower(exp[i]));
			printf("%c", exp[i]);
		}
		else if (exp[i] >= 'a'&&exp[i] <= 'z')
		{
			push(s, exp[i]);
			printf("%c", exp[i]);
		}
	}
	printf("\n");

	for (int i = 0; i <= (s->top / 2); i++)
	{
		if (pop(s) != s->data[i])
			return 0;
	}
	return 1;
}