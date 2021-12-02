#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}DequeType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;
}
int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void deque_print(DequeType *q)
{
	printf("DEQUE(front= %d rear= %d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
void add_front(DequeType *q, element val)
{
	if (is_full(q))
		error("덱 포화상태입니다.\n");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
element delete_front(DequeType *q)
{
	if (is_empty(q))
		error("덱 공백상태입니다.\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element get_front(DequeType *q)
{
	if (is_empty(q))
		error("덱 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
void add_rear(DequeType *q, element item)
{
	if (is_full(q))
		error("덱 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear]=item ;
}
element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("덱 공백상태입니다.");
	q->rear = (q->rear - 1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}
element get_rear(DequeType *q)
{
	if (is_empty(q))
		error("덱 공백상태입니다.");
	return q->data[q->rear];
}

element create_customer(int clock)
{
	element customer;
	customer.id ;
	customer.arrival_time = clock;
	customer.service_time = rand() % 5 + 1;
	return customer;
}

int amount_queue(DequeType q)
{
	int count;
	count = q -> rear - q -> front;
	if (count < 0) count += MAX_QUEUE_SIZE;
	return count;
}

int sorting(int *count)
{
	int temp, low_count_queue = 0;
	for(int i=1;i<3;i++)
		if (count[i] < count[0])
		{
			temp = count[i];
			count[i] = count[0];
			low_count_queue = i;
		}
	return low_count_queue;
}
int main()
{
	int minutes = 0;
	int total_wait = 0;
	int count_table[3] = { 0.0,0 };
	int service_time[3] = { 0,0,0 };
	int service_customer[3] = { 0,0,0 };

	DequeType q[3];
	for (int i = 0; i < 3; i++)
		init_deque(&q);

	srand((unsigned)time(NULL));

	for (int clock = 0; clock < minutes; clock++)
	{
		printf("����ð�=%d\n", clock);
		if (rand() % 10 < 4) {
			element customer;
			customer = create_customer(clock);
			for (int i = 0; i < 3; i++)
			{
				count_table[i] = amount_queue(q[i]);
			}
			int low_count_queue = sorting(count_table);
			add_rear(&q[low_count_queue],customer);
			printf("%d�� ���� ���� %d���� %d�п� ���ɴϴ�. ����ó���ð�=%d��\n",low_count_queue,customer.id,customer.arrival_time,customer.service_time);
		}
		for (int i = 0; i < 3; i++)
		{
			if (service_time[i] > 0)
			{
				printf("%d�� ���� ���� %d���� ����ó�����Դϴ�. \n", i, service_customer[i]);
				service_time[i]--;
			}
			else
			{
			re: 
				if (!is_empty(&q[i]))
				{
					element customer = delete_front(&q[i]);
					service_customer[i] = customer.id;
					service_time[i] = customer.service_time;
					printf("%d�� ���� ���� %d���� %d�п� ������ �����մϴ�. ���簣�� %d���̾����ϴ�.\n",i,customer.id,clock,clock-customer.arrival_time);
				}
				else
				{
					int bigger, q1, q2;
					q1 = amount_queue(q[(i + 1) % 3]);
					q2 =amount_queue(q[(i + 2) % 3]);
					if (q1 != 0 || q2 != 0)
					{
						bigger = (q1 >= q2) ? (i + 1) % 3 : (i + 2) % 3;
						add_rear(&q[i], delete_rear(&q[bigger]));
						printf("%d�� ������ %d�� ���� ������ ������ �Խ��ϴ�.\n", i, bigger);
						printf("%d��", bigger);
						deque_print(&q[bigger]);


					}

				}


			}
		}
	}

}