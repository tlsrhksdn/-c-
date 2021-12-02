#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

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

int eval(char exp[])
{
    int op1,op2,value;
    int len=strlen(exp);
    char ch;
    StackType s;

    init_stack(&s);
    for(int i=0;i<len;i++)
    {
        ch=exp[i];
        if(ch!='+' && ch!='-' &&ch!='*' &&ch!='/')
        {
            value=ch-'0';
            push(&s,value);
        }
        else{
            op2=pop(&s);
            op1=pop(&s);
            switch(ch){
            case '+':
            push(&s,op1+op2);
            break;
            case '-':
            push(&s,op1-op2);
            break;
            case '*':
            push(&s,op1*op2);
            break;
            case '/':
            push(&s,op1/op2);
            break;
            }
        }
    }
    return pop(&s);
}