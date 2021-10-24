#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

//큐 구조체 정의
typedef int element;

typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front,rear;
}QueueType;
//에러 출력
void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
//큐 초기화
void init_queue(QueueType *q)
{
	q->front=-1;
	q->rear=-1;
}
//큐 공백상태 함수
int is_empty(QueueType *q)
{
	return q->front==q->rear;
}
//큐 포화상태 함수
int is_full(QueueType *q)
{
	return q->rear=MAX_QUEUE_SIZE-1;
}
//큐 원소 삽입 함수
void enqueue(QueueType *q,element item)
{
	if(is_full(q))
	{
		error(stderr,"스택 포화 에러");
		return;
	}
	q->data[++(q->rear)]=item;
}
//큐 원소 삭제 함수
element dequeue(QueueType *q)
{
	if(is_empty(q))
	{
		error(stderr,"스택 공백 에러");
		exit(1);
	}
	return q->data[++(q->front)];
}
//큐 원소 출력 함수(삭제 x)
element  peek(QueueType *q)
{
	if(is_empty(q))
	{
		error(stderr,"스택 공백 에러");
		exit(1);
	}
	element item=q->data[++(q->front)];
	return item;
}
//큐 전체 출력 함수
void print_queue(QueueType *q)
{
	for(int i=0;i<MAX_QUEUE_SIZE;i++)
	{
		if(i<q->front || i>q->rear)
		printf(" | ");
		else
		printf("%d | ",q->data[i]);
	}
	printf("\n");
}
