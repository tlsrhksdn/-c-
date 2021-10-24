#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

//큐 구조체 입력
typedef int element;

typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front,rear;
}QueueType;
//에러 메시지 출력
void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
//큐 초기화 함수
void init_queue(QueueType *q)
{
	q->front=0;
	q->rear=0;
}
//큐 공백상태 함수
int is_empty(QueueType *q)
{
	return (q->front==q->rear);
}
//큐 포화상태 함수
int is_full(QueueType *q)
{
	return (q->rear+1)%MAX_QUEUE_SIZE==q->front;
}
//큐 전체 출력
void print_queue(QueueType *q)
{
	printf("Queue(front=%d rear=%d)",q->front,q->rear);
	if(!is_empty(q))
	{
		int i=q->front;
		do{
			i=(i+1)%MAX_QUEUE_SIZE;
			printf("%d | ",q->data[i]);
			if(i==q->rear)
			break;
		}while(i!=q->front);
	
	}
	printf("\n");
}
//큐에 원소 입력 함수
void enqueue(QueueType *q,element item)
{
	if(is_full(q))
		error("스택 포화상태입니다.");
	q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
	q->data[q->rear]=item;
}
//큐에 원소 삭제 후 출력 함수
element dequeue(QueueType *q)
{
	if(is_empty(q))
	error("스택 공백상태입니다.");
	q->front=(q->front+1)%MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//큐에 원소 삭제하지 않고 출력 함수
element peek(QueueType *q)
{
	if(is_empty(q))
	error("스택 공백상태입니다.");
	return q->data[q->front];
}
