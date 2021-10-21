//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<ctype.h>
//
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
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
//
//void main()
//{
//	int letter_count = 0;
//	char top;
//	char line[100];
//	StackType s;
//	init_stack(&s);
//	printf("문자열: ");
//	gets_s(line, sizeof(line));
//	for (int i = 0; i < sizeof(line); i++)
//	{
//		line[i] = tolower(line[i]);
//	}
//	printf("압축된 문자열: ");
//	for (int i = 0; i < strlen(line); i++)
//	{
//		if (is_empty(&s))
//			letter_count = 1;
//		if (sizeof(&s) > 0)
//		{
//			top = peek(&s);
//			if (top == line[i])
//				letter_count++;
//			if ((top != line[i]) || (i = strlen(line)-1)) {
//				printf("%d", letter_count);
//				printf("%c", top);
//				letter_count = 1;
//			}
//		}
//		push(&s, line[i]);
//	}
//}