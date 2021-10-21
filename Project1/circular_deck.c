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
//�� �ʱ�ȭ
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;
}
//�� empty
int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}
//full
int is_full(DequeType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
//�� ���� ���
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
//�ĸ鿡 ���� �߰�
void add_rear(DequeType *q, element item)
{
	if (is_full(q))
		error("ť ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//���� ���� ����,���
element delete_front(DequeType *q)
{
	if (is_empty(q))
		error("ť ��ȭ�����Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//���� ���� ���(���� x)
element get_front(DequeType *q)
{
	if (is_full(q))
		error("ť ��ȭ�����Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//���� ���� �߰�
void add_front(DequeType *q, element item)
{
	if (is_fulll(q))
		error("���� ��ȭ�����Դϴ�.");
	q->data[q->front] = item;
	q->front = (q->front - 1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
//�ĸ� ���� ���� ,���
element delete_rear(DequeType *q)
{
	if (is_empty(q))
		error("���� ��������Դϴ�.");
	element temp = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return temp;
}
//�ĸ� ���� ���(���� x)
element get_rear(DequeType *q)
{
	if (is_empty(q))
		error("���� ��������Դϴ�.");
	return q->data[q->rear];
}