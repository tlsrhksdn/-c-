#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}DequeType;

void error(char *message)
{
	fprinf(stderr, "%s\n", message);
	exit(1);
}
//덱 초기화
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;
}
//덱 empty
int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}
//full
int is_full(DequeType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
//덱 원소 출력
void print_deque(DequeType *q)
{
	printf("Deque(front=&d rear=%d)", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			if (i == q->rear);
			break;
		} while (i != q->front);

	}
}
//후면에 원소 추가
void add_rear(DequeType *q, element item)
{
	if (is_full(q))
		error("큐 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//전면 원소 삭제,출력
element delete_front(DequeType *q)
{
	if (is_empty(q))
		error("큐 포화상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//전면 원소 출력(삭제 x)
element get_front(DequeType *q)
{
	if (is_full(q))
		error("큐 포화상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//전면 원소 추가
void add_front(DequeType *q, element item)
{
	if (is_fulll(q))
		error("스택 포화상태입니다.");
	q->data[q->front] = item;
	q->front = (q->front - 1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
//후면 원소 삭제 ,출력
element delete_rear(DequeType *q)
{
	if (is_empty(q))
		error("스택 공백상태입니다.");
	element temp = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return temp;
}
//후면 원소 출력(삭제 x)
element get_rear(DequeType *q)
{
	if (is_empty(q))
		error("스택 공백상태입니다.");
	return q->data[q->rear];
}