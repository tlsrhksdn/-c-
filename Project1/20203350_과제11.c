#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENT 200
#define MAX_ELEMENT_SIZE 50

typedef struct {
	char str[MAX_ELEMENT_SIZE];   //����
	int key; //����
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
//���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; //���ο� ��带 ����
}
//���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		//���� ����� �ڽĳ�� �� �� ū �ڽĳ�带 ���´�
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		//�� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
//�켱���� ť�� ������ �̿��� ����
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
		printf("����(i),����(d) : ");
		scanf_s(" %c", &ch, sizeof(ch));
		if (ch == 'i') {
			printf("����: ");
			getchar();
			gets_s(e.str, MAX_ELEMENT_SIZE);

			//scanf_s("%[^\n]s", e.str,MAX_ELEMENT_SIZE);

			//scanf_s("%s", e.str, MAX_ELEMENT_SIZE);
			printf("�켱����: ");
			scanf_s("%d", &e.key); //����

			insert_max_heap(heap, e);
		}
		else if (ch == 'd') {
			e = delete_max_heap(heap);
			printf("���� �켱 ������ ���� ���� '%s'\n", e.str);
		}
		else
			printf("\n���ڸ� �߸� �Է��߽��ϴ�.\n");
	}

	return 0;

}