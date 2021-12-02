#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENT 200
#define MAX_ELEMENT_SIZE 50

typedef struct {
	char str[MAX_ELEMENT_SIZE];   //수정
	int key; //수정
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}
//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; //새로운 노드를 삽입
}
//삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		//현재 노드의 자식노드 중 더 큰 자식노드를 갖는다
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		//힌 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
//우선순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}


int main()
{
	char ch;

	element e;
	HeapType* heap;

	heap = create();
	init(heap);

	while (heap->heap_size < MAX_ELEMENT)
	{
		printf("삽입(i),삭제(d) : ");
		scanf_s(" %c", &ch, sizeof(ch));
		if (ch == 'i') {
			printf("할일: ");
			getchar();
			gets_s(e.str, MAX_ELEMENT_SIZE);

			//scanf_s("%[^\n]s", e.str,MAX_ELEMENT_SIZE);

			//scanf_s("%s", e.str, MAX_ELEMENT_SIZE);
			printf("우선순위: ");
			scanf_s("%d", &e.key); //수정

			insert_max_heap(heap, e);
		}
		else if (ch == 'd') {
			e = delete_max_heap(heap);
			printf("제일 우선 순위가 높은 일은 '%s'\n", e.str);
		}
		else
			printf("\n문자를 잘못 입력했습니다.\n");
	}

	return 0;

}