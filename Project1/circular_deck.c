#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5
//덱 구조체 생성
typedef int element;

typedef struct{
	int front,rear;
	element data[MAX_QUEUE_SIZE];
}DequeType;
//에러 출력 함수
void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
//덱 초기화 함수
void init_deque(DequeType *q)
{
	q->front=0;
	q->rear=0;
}
//덱 공백출력 함수
int is_empty(DequeType *q)
{
	return q->front==q->rear;
}
//덱 포화상태 함수
int is_full(DequeType *q)
{
	return (q->rear+1)%MAX_QUEUE_SIZE==q->front;
}
//덱의 모든원소 출력함수
void print_deque(DequeType *q)
{
	printf("DEque(front=%d rear=%d) = ",q->front,q->rear);
	if(!is_empty(q))
	{
		int i=q->front;
		do
		{
			i=(i+1)%MAX_QUEUE_SIZE;
			printf("%d | ",q->data[i]);
			if(i==q->rear)
			break;
		} while (i!=q->front);
	}
	printf("\n");
}
//덱의 후면에 원소삽입 함수
void add_rear(DequeType *q,element item)
{
	if(is_full(q))
	error("큐가 포화상태입니다.");
	q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
	q->data[q->rear]=item;
}
//덱의 전면 원소 삭제후 출력함수
element delete_front(DequeType *q)
{
	if(is_empty(q))
	error("큐가 공백상태입니다.");
	q->front=(q->front+1)%MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//덱의 전면 원소 삭제하지 않고 출력함수
element get_front(DequeType *q)
{
	if(is_empty(q))
	error("큐가 공백상태입니다.");
	return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}
//덱의 전면에 원소삽입 함수
void add_front(DequeType *q,element item)
{
	if(is_full(q))
	error("큐가 포화상태입니다.");
	q->data[q->front]=item;
	q->front=(q->front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
	
}
//덱의 후면에 원소 삭제하고 출력함수
element delete_rear(DequeType *q)
{
	if(is_empty(q))
	error("큐가 공백상태입니다.");
	element item=q->data[q->rear];
	q->rear=(q->rear-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
	return item;
}
//덱의 후면에 원소 삭제하지 않고 출력함수
element get_rear(DequeType *q)
{
	if(is_empty(q))
	error("큐가 공백상태입니다.");
	return q->data[q->rear];
}