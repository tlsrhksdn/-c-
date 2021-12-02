// 2�� 83������ ����4�� ù��° ���
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct { 			// ���׽� ����ü Ÿ�� ����
	int degree;			// ���׽��� ����
	float coef[MAX_DEGREE];	// ���׽��� ���
} polynomial;

// C = A+B ���⼭ A�� B�� ���׽��̴�. ����ü�� ��ȯ�ȴ�. 
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;				// ��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0;	// �迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	int tmp = 0;
	C.degree = MAX(A.degree, B.degree); // ��� ���׽� ����

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {  // A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;			
		}
		else {			// B�� > A��
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}
void get_poly(polynomial *a, polynomial *b)    //poly_add()
{
	int i;
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, "poly01.txt", "rt");		//������Ʈ ���ο� �ؽ�Ʈ���� ������ ��
	if (NULL != fp) 
	{
		fscanf_s(fp, "%d", &(*a).degree); 
		for (i = 0; i <= (*a).degree; i++)
			fscanf_s(fp, "%f", &(*a).coef[i]);

		fscanf_s(fp, "%d", &(*b).degree);
		for (i = 0; i <= (*b).degree; i++)
			fscanf_s(fp, "%f", &(*b).coef[i]);

		fclose(fp);
	}
	else
		printf(" ���� ���� ���� \n");
}
////while�� Ȱ���� ���� �����
//void get_poly01(polynomial *terms)
//{
//	int i = 0;
//	FILE *fp;
//	errno_t err;
//	err = fopen_s(&fp, "poly02.txt", "rt");
//	if (NULL != fp)
//	{
//		while (EOF != fscanf_s(fp, "%f,%d", &terms[i].coef, &terms[i].expon))
//			i++;
//		fclose(fp);
//	}
//	else
//		printf("���� ���� ����\n");
//}




// ���Լ�
int main(void)
{
	//polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	//polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
	//polynomial c;
	polynomial a, b, c;

	get_poly(&a, &b);
	
	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(c);
	
	
	return 0;
}

//// 2�� 83������ ����4�� �ι�° ���
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_TERMS 101
//typedef struct {
//	float coef;
//	int expon;
//} polynomial;
//polynomial terms[MAX_TERMS]; // = { { 8,3 },{ 7,1 },{ 1,0 },{ -8,3 },{ 3,2 },{ 1,0 } };
//int avail = 6;
//
//// �ΰ��� ������ ��
//char compare(int a, int b)
//{
//	if (a > b) return '>';
//	else if (a == b) return '=';
//	else return '<';
//}
//
//// ���ο� ���� ���׽Ŀ� �߰��Ѵ�.
//void attach(float coef, int expon)
//{
//	if (avail > MAX_TERMS) {
//		fprintf(stderr, "���� ������ �ʹ� ����\n");
//		exit(1);
//	}
//	terms[avail].coef = coef;
//	terms[avail].expon = expon;
//	avail++;
//}
//
//// C = A + B
//void poly_add2(int As, int Ae, int Bs, int Be, int* Cs,
//	int* Ce)
//{
//	float tempcoef;
//	*Cs = avail;
//	while (As <= Ae && Bs <= Be)
//		switch (compare(terms[As].expon, terms[Bs].expon)) {
//		case '>': 	// A�� ���� > B�� ����
//			attach(terms[As].coef, terms[As].expon);
//			As++;			break;
//		case '=': 	// A�� ���� == B�� ����
//			tempcoef = terms[As].coef + terms[Bs].coef;
//			if (tempcoef)
//				attach(tempcoef, terms[As].expon);
//			As++; Bs++;		break;
//		case '<': 	// A�� ���� < B�� ����
//			attach(terms[Bs].coef, terms[Bs].expon);
//			Bs++;			break;
//		}
//	// A�� ������ �׵��� �̵���	
//	for (; As <= Ae; As++)
//		attach(terms[As].coef, terms[As].expon);
//	
//	// B�� ������ �׵��� �̵���
//	for (; Bs <= Be; Bs++)
//		attach(terms[Bs].coef, terms[Bs].expon);
//	*Ce = avail - 1;
//}
//void print_poly(int s, int e)
//{
//	for (int i = s; i <= e; i++)
//		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
//	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
//}
//
//void get_poly01(polynomial* terms)
//{
//	int i=0;
//	FILE* fp;
//	errno_t err;
//	err = fopen_s(&fp, "poly02.txt", "rt");
//	if (NULL != fp)
//	{
//		while (EOF != fscanf_s(fp, "%f %d", &terms[i].coef, &terms[i].expon))
//			i++;
//		fclose(fp);
//	}
//	else
//			printf(" ���� ���� ���� \n");
//}
//
////
//int main(void)
//{
//	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
//	get_poly01(terms);
//	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
//	print_poly(As, Ae);
//	print_poly(Bs, Be);
//	printf("-----------------------------------------------------------------------------\n");
//	print_poly(Cs, Ce);
//	return 0;
//}
//
//#include <stdio.h>
//
////2�� �������� 5�� �̸�(���ڹ迭), ����, �޿�
//struct person
//{
//	char name[20];
//	int age;
//	float salary;
//};
////���� 6�� & 7�� ���Ҽ� ����ü �� ���Ҽ� ���ϱ� �Լ�
//typedef struct
//{
//	float real;
//	float imag;
//} complex;
//complex complex_add(complex a, complex b) 
//{	
//	complex result;
//	result.real = a.real + b.real;
//	result.imag = a.imag + b.imag;
//	return result;
//}
//int main(void)
//{
//	struct person man1;
//	strcpy(man1.name, "hongkildong");
//	man1.age = 21;
//	man1.salary = 5000;
//	printf("\nman1: name=%s age=%d salary=%6.1f\n\n", man1.name, man1.age, man1.salary);
//	complex a = { 10, 5 };
//	complex b = { 31, 22 };
//	complex result;
//	result = complex_add(a, b);
//	printf("result is %3.1f + %3.1fi\n\n", result.real, result.imag);
//	return 0;
//}
//
//
//// 2�� 94������ ����2�� ����������
//#include <stdio.h>
//typedef struct {
//	int x;
//	int y;
//}Point;
//void change_point(Point** ppa, Point** ppb) //���������͸� �Ű������� ���
//{
//	Point* tmp;
//	tmp = *ppa;
//	*ppa = *ppb;
//	*ppb = tmp;
//}
//void change_point00(Point* ppa, Point* ppb) // �����͸� �Ű������� ���
//{
//	Point* tmp;
//	tmp = ppa;
//	ppa = ppb;
//	ppb = tmp;
//	printf("�Լ� �ȿ��� ����\n");
//	printf("%d %d %d %d\n", (*ppa).x, (*ppa).y, (*ppb).x, (*ppb).y);
//
//}
//
//int main(void)
//{
//
//	Point pa = { 2,3 };
//	Point pb = { 20,30 };
//
//	Point* ppa = &pa;
//	Point* ppb = &pb;
//
//	printf("��������\n");
//	printf("%d %d %d %d\n", (*ppa).x, (*ppa).y, (*ppb).x, (*ppb).y);
//
//	//������ �ּҸ� �˷� �־��� ��
//	change_point00(ppa, ppb);
//	printf("�Լ� change_point00 ������ main���� \n");
//	printf("%d %d %d %d\n", (*ppa).x, (*ppa).y, (*ppb).x, (*ppb).y);
//
//	//������ �ּҸ� ������ �ִ� ������ �ּҸ� �˷� �־��� ��
//	change_point(&ppa, &ppb);
//	printf("�Լ� change_point ������ main���� \n");
//	printf("%d %d %d %d\n", (*ppa).x, (*ppa).y, (*ppb).x, (*ppb).y);
//	return 0;
//}