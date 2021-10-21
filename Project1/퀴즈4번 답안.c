/*
ù��° ���
#include<stdio.h>
#define MAX(a,b)(((a)>(b)) ? (a):(b))
#define MAX_DEGREE 101
#define FILE_MAX 100001
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;
	int Apos=0, Bpos=0, Cpos=0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b)
		{
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;		
		}
		else if (degree_a == degree_b)
		{
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else
		{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
	{
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

polynomial poly_read(char* filename) {
	// n, { num_0, num_1 ... num_n-1}
	FILE* fp;
	fp = fopen(filename, "r");

	polynomial res;
	char buf[FILE_MAX];

	memset(buf, 0, sizeof(buf));
	fgets(buf, sizeof(buf), fp);

	int num = 0; // ���Ͽ��� ���� bite�� ���� ��ȯ�ϱ� ���� ����
	int index = -1; // coef �迭�� �� �ε����� �ǹ�
	for (int i = 0; ; i++) {
		if (buf[i] != ' ') {
			if (buf[i] == '\0') { // ������ �������� �о����Ƿ� ������ ���� �־��� �� �ݺ����� ��������
				res.coef[index++] = num;
				break;
			}
			else { 
			// ���ڿ��� ���� �޾����Ƿ� int�� ��ȯ
			// ex) '5' �� 5�� �ޱ� ���� '5'-'0' ���� (�ƽ�Ű�ڵ�)m
				num = num * 10 + (int)(buf[i] - '0');
			}
		}
		else {
			// ������ �о��� ��,
			if (index == -1) { // index �� -1�̶�� �ִ� ������ �о����Ƿ� degree�� �����Ѵ�.
				res.degree = num;
				index++; // index 1 ����
			}
			else {
			// ����� �ǹ��ϹǷ� index��° num�� �־��ְ� index�� 1 ������Ŵ
				res.coef[index++] = num;
			}
			num = 0;
		}
	}
	return res;
}

int main()
{
	polynomial a = poly_read("poly1.txt");
	polynomial b = poly_read("poly2.txt");
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("------------------------------------------------------\n");
	print_poly(c);
	return 0;
}

*/


//�ι�° ���

#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 101
#define FILE_MAX 100001
typedef struct {
	float coef;
	int expon;
}polynomial;
//polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
polynomial terms[MAX_TERMS];
int avail = 6;

void poly_read(char * filename) {
	FILE* fp;
	fp = fopen(filename, "r"); // ������ �о ���� �����Ϳ� ����.

	char buf[FILE_MAX]; // ���� ������ bite�� �����ϱ� ���� �迭

	memset(buf, 0, sizeof(buf)); // �迭 �ʱ�ȭ, NULL ������ �ʱ�ȭ�Ѵ�.
	fgets(buf, sizeof(buf), fp); // ������ �о buf �迭�� ����

	int num = 0; // ���� ���ڸ� �����ϴ� ����
	int index = 0; // ���° �������� ǥ���ϱ����� �ε��� ����
	for (int i = 0;  ; i++) {
		if (buf[i] == ' ' || buf[i] == '\0') { // �����̰ų� ������ ���ΰ��
			// index / 2 �� ���ִ� ������ 
			// a b c d ���� a*x^b + c*x^d �̹Ƿ� �ΰ��� ¦�� �̷��.
			if (index & 1) { // �ε����� Ȧ����� ������ �ش��ϴ� ���̹Ƿ�
				terms[index / 2].expon = num; 
			}
			else { // �ε����� ¦����� ����̹Ƿ� ����� ����
				terms[index / 2].coef = num;
			}
			num = 0; // ���� ���� �ޱ����� 0���� �ʱ�ȭ
			index++; // �ε����� 1 ������Ų��.
			if (buf[i] == '\0') { // ������ �� �о��ٸ� ��������
				break;
			}
		}
		else {
			// ���ڿ��� ���� �޾����Ƿ� int�� ��ȯ
			// ex) '5' �� 5�� �ޱ� ���� '5'-'0' ���� (�ƽ�Ű�ڵ�)
			num = num * 10 + (int)(buf[i] - '0');
		}
	}
	return;
}

char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
	{
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
	{
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case '>':
			attach(terms[As].coef, terms[As].expon);
			As++; break;

		case '=':
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++; Bs++; break;
		case '<':
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++; break;
		}
		for (; As <= Ae; As++)
			attach(terms[As].coef, terms[As].expon);
		for (; Bs <= Be; Bs++)
			attach(terms[Bs].coef, terms[Bs].expon);
		*Ce = avail - 1;
	}	
}

void print_poly(int s,int e)
{
	for (int i =s;i<e;i++)
	{
		printf("%3.1fx^%d + ",terms[i].coef,terms[i].expon);
	}
	printf("%3.1f^%d \n", terms[e].coef,terms[e].expon);
}
int main()
{
	poly_read("poly3.txt");
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;

	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);

	print_poly(As,Ae);
	print_poly(Bs,Be);
	
	printf("------------------------------------------------------\n");
	print_poly(Cs,Ce);
	return 0;
}
