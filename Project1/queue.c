#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q)
{
	q->front = -1;
	q->rear=-1;
}

int is_empty(QueueType *q)
{
	return (q->front = q->rear);
}

int is_full(QueueType *q)
{
	return q->rear = MAX_QUEUE_SIZE - 1;
}

void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("ť ��ȭ�����Դϴ�.");
	q->data[(q->rear)++] = item;
}
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("ť ��������Դϴ�.");
	return q->data[++(q->front)];
}
element peek(QueueType *q)
{
	if (is_empty(q))
		error("ť ��������Դϴ�.");
	return q->data[(q->front)];
}