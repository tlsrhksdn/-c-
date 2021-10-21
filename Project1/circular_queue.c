#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;

//원형 큐 정의
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//에러 출력
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//원형 큐 초기화
void init_queue(QueueType *q)
{
	q->front = q->rear=0;
	return;
}

//원형 큐 빔
int is_empty(QueueType *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
//원형 큐 가득참
int is_full(QueueType *q)
{
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
		return 1;
	else
		return 0;
}
//원형 큐 출력
void queue_print(QueueType *q)
{
	printf("QUEUE(front=&d,rear=%d) = ", q->front, q->rear);
	if (!is_empty)
	{
		int i = q->front; //q->front를 담는 변수 i 생성
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
//원형 큐 원소 입력
void enqueue(QueueType *q,element item)
{
	if (is_full(q))
	{
		error("큐가 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//원형 큐 원소 출력
element dequeue(QueueType *q)
{
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element peek(QueueType *q)
{
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");
	}
	return (q->front + 1) % MAX_QUEUE_SIZE;	
}