//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define MAX_QUEUE_SIZE 100
//
//typedef char element;
//
//typedef struct {
//	int front;
//	int rear;
//	element data[MAX_QUEUE_SIZE];
//}QueueType;
//
//void error(char *message)
//{
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType *q)
//{
//	q->front = -1;
//	q->rear = -1;
//}
//void queue_print(QueueType *q)
//{
//	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
//	{
//		if (i <= q->front || i >= q->rear)
//		{
//			printf(" | ");
//		}
//		else
//			printf("%d | ", q->data[i]);
//	}
//	printf("\n");
//}
//int is_full(QueueType *q) 
//{
//	if (q->rear = MAX_QUEUE_SIZE - 1)
//		return 1;
//	else
//		return 0;
//}
//int is_empty(QueueType *q)
//{
//	if (q->front == q->rear)
//		return 1;
//	else
//		return 0;
//}
//void enqueue(QueueType *q, int item)
//{
//	if (is_full(q))
//	{
//		printf("큐가 포화 상태입니다.");
//		exit(1);
//	}
//	else
//		q->data[++(q->rear)] = item;
//}
//element dequeue(QueueType *q)
//{
//	if (is_empty(q))
//	{
//		printf("큐가 공백 상태입니다.");
//		exit(1);
//	}
//	else
//	{
//		int item = q->data[++(q->front)];
//		return item;
//	}
//}
////큐 코드 작성완료
//
////내가 작성한 코드
////int check_palindrome(QueueType *q,char exp[])
////{
////	int i = 0, len = strlen(exp);
////	
////
////	while (exp[i] != NULL)
////	{
////		if (exp[i] < 65 || (exp[i] > 90 && exp[i] < 97) || exp[i]>122)
////		{
////			while (q->data!=NULL)
////				dequeue(&q);
////		}
////		enqueue(&q, exp[i]);
////	}
////
////	for (int i = 0; i < (len+1)/2 ;i++)
////	{
////		int n = (len + 1) / 2;
////		if (q->data[i] != q->data[n])
////		{
////			return 0;
////			break;
////		}		
////	}
////	return 1;
////}
//
////교수님께서 작성하신 코드
//int check_palindrome(QueueType *q, char exp[])
//{
//	int i = 0, len = strlen(exp);
//
//	for (int i = 0; i <= (len / 2); i++)
//		enqueue(q, exp[i]);
//	for (int i = 0; i <= (len / 2); i++)
//	{
//		if (dequeue(q) != exp[len - (i + 1)])
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	QueueType q;
//	init_queue(&q);
//
//	//char *str=NULL;
//	char str[MAX_QUEUE_SIZE];
//	printf("문자열을 입력하세요:  ");
//	scanf_s("%s", &str,sizeof(str));
//	
//	int result=check_palindrome(&q,str);
//	if (result == 1)
//		printf("회문입니다.");
//	else
//		printf("회문이 아닙니다.");
//	return 0;
//}