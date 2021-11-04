#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct LinkedList {
	int coef; //차수
	int expon;  //계수
	struct LinkedList* link;
}LinkedList;

typedef struct ListType {
	int size;
	LinkedList* head;
	LinkedList* tail;
}ListType;


void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create()
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
void insert_last(ListType* plist, int coef, int expon)
{
	LinkedList* temp = (LinkedList*)malloc(sizeof(LinkedList));
	if (temp == NULL)
		error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

int poly_eval(ListType *plist,int n)
{
	int sum = 0;
	for (LinkedList* p = plist->head; p != NULL; p = p->link)
	{
		if (p->expon == 0)
			sum += p->coef;
		else
			sum += p->coef * pow(n,p->expon);
	}
	return sum;
}
void poly_print(ListType* plist)
{
	LinkedList* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link)
		printf("%d^%d + ", p->coef, p->expon);
	printf("\n");
}
int main()
{
	ListType* p;

	p = create();

	insert_last(p, 1, 3);
	insert_last(p, 2, 1);
	insert_last(p, 6,0);
	poly_print(p);
	
	printf("다항식의 계산값은 %d입니다.", poly_eval(p, 2));

	return 0;
}