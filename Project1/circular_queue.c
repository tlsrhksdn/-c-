#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;

//���� ť ����
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//���� ���
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//���� ť �ʱ�ȭ
void init_queue(QueueType *q)
{
	q->front = q->rear=0;
	return;
}

//���� ť ��
int is_empty(QueueType *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
//���� ť ������
int is_full(QueueType *q)
{
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
		return 1;
	else
		return 0;
}
//���� ť ���
void queue_print(QueueType *q)
{
	printf("QUEUE(front=&d,rear=%d) = ", q->front, q->rear);
	if (!is_empty)
	{
		int i = q->front; //q->front�� ��� ���� i ����
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
//���� ť ���� �Է�
void enqueue(QueueType *q,element item)
{
	if (is_full(q))
	{
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//���� ť ���� ���
element dequeue(QueueType *q)
{
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element peek(QueueType *q)
{
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�.");
	}
	return (q->front + 1) % MAX_QUEUE_SIZE;	
}