#include<stdio.h>
#include<stdio.h>
#include<string.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct{
    int top;
    element data[MAX_STACK_SIZE];
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

int check_matching(const char *in)
{
    StackType s;
    char ch,open_ch;

    init_stack(&s);

    for(int i=0;i<strlen(in);i++)
    {
        ch=in[i];
        switch(ch)
        {
            case '(': case '[': case '{':
            push(&s,ch);
            break;
            case ')': case '}': case ']':
            if(is_empty(&s))
            return 0;
            else
            {
                open_ch=pop(&s);
                if((open_ch=='('|| ch!=')')||(open_ch=='{'|| ch!='}')||(open_ch=='['|| ch!=']'))
                return 0;
            }
            break;
        }
    }
    if(!is_empty(&s))
    return 0;
    else
    return 1;
} 
