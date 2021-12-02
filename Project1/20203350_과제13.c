#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ELEMENT 200

typedef struct {
	int key;
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
void print_heap(HeapType* h)
{
	for (int i = 1; i <= h->heap_size; i++)
		printf("<%d>", h->heap[i].key);
	printf("\n");
}
int main()
{
	element e[9];
	HeapType* heap;

	heap = create();
	init(heap);

	FILE* fp;
	errno_t err;

	int i = 0;

	err = fopen_s(&fp, "heap01.txt", "rt");
	if (NULL != fp)
	{
		while (EOF != fscanf_s(fp, "%d", &e[i].key))
		{
			insert_max_heap(heap, e[i]);
			print_heap(heap);
			i++;
		}
		fclose(fp);
	}


	printf("\n배열에 저장된 내용\n");
	print_heap(heap);

	delete_max_heap(heap);
	printf("\n최대값을 한번 제거한 후 배열의 내용\n");
	print_heap(heap);

	free(heap);
	return 0;
}