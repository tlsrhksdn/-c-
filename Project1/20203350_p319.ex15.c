#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

//원형큐 코드 시작
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
void check_list(TreeNode* ptr,int value)
{
	QueueType q;
	init_queue(&q);

	if (ptr == NULL)
		return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		if (ptr->data< value)
			printf("30보다 작은 노드: %d\n", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;

int main(void)
{
	int num;

	printf("값을 입력하시오: ");
	scanf_s("%d", &num, sizeof(num));
	check_list(root, num);
	return 0;
}