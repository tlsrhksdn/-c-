#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct{
    int id;
    int arrival_time;
    int service_time;
}element;
typedef struct{
    int front,rear;
    element data[MAX_QUEUE_SIZE];
}DequeType;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_deque(DequeType *q)
{
    q->front=q->rear=0;
}
int is_empty(DequeType *q)
{
    return q->front==q->rear;
}
int is_full(DequeType *q)
{
    return (q->front+1)%MAX_QUEUE_SIZE==q->rear;
}
void add_rear(DequeType *q,element item)
{
    q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear]=item;
}
element delete_rear(DequeType *q)
{
    element item=q->data[q->rear];
    q->rear=(q->rear-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
    return item;
}
element get_rear(DequeType *q)
{
    return q->data[q->rear];
}
void add_front(DequeType *q,element item)
{
    q->data[q->front]=item;
    q->front=(q->front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
}
element delete_front(DequeType *q)
{
    q->front=(q->front+1)%MAX_QUEUE_SIZE;
    element item=q->data[q->front];    
    return item;
}
element get_front(DequeType *q)
{
    return q->data[(q->front+1)%MAX_QUEUE_SIZE]; 
}
void print_deque(DequeType *q)
{
    printf("DEQUE(front=%d,rear=%d) = ",q->front,q->rear);
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
void main()
{
    int minutes=60;
    int total_wait=0;
    int total_customers=0;
    int service_time=0;
    int service_customer;
    DequeType q;
    init_deque(&q);

    srand(time(NULL));
    for(int clock=0;clock<minutes;clock++)
    {
        printf("현재시간=%d\n",clock);
        if((rand()%10)<3){
            element customer;
            customer.id=total_customers++;
            customer.arrival_time=clock;
            customer.service_time=rand()%3+1;
            add_rear(&q,customer);
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",customer.id,customer.arrival_time,customer.service_time);
        }
       if(service_time>0)
       {
           printf("고객 %d 업무처리중입니다. \n",service_customer);
           service_time--;
       }
       else
       if(!is_empty(&q)){
           element customer=delete_rear(&q);
           service_customer=customer.id;
           service_time=customer.service_time;
           printf("고객 %d이 %d분에 업  무를 시작합니다. 대기시간은 %d분이었습니다. \n",customer.id,clock,clock-customer.arrival_time);
           total_wait+=clock-customer.arrival_time;
       }
       }
       printf("전체 대기 시간=%d분 \n",total_wait);
       return 0;
}