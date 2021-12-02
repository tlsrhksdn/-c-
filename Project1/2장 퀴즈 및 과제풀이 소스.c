// 2장 83페이지 퀴즈4번 첫번째 방식
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct { 			// 다항식 구조체 타입 선언
	int degree;			// 다항식의 차수
	float coef[MAX_DEGREE];	// 다항식의 계수
} polynomial;

// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다. 
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;				// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	int tmp = 0;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {  // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;			
		}
		else {			// B항 > A항
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
	err = fopen_s(&fp, "poly01.txt", "rt");		//프로젝트 내부에 텍스트파일 존재할 때
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
		printf(" 파일 열기 실패 \n");
}
////while문 활용한 파일 입출력
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
//		printf("파일 열기 실패\n");
//}




// 주함수
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

//// 2장 83페이지 퀴즈4번 두번째 방식
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
//// 두개의 정수를 비교
//char compare(int a, int b)
//{
//	if (a > b) return '>';
//	else if (a == b) return '=';
//	else return '<';
//}
//
//// 새로운 항을 다항식에 추가한다.
//void attach(float coef, int expon)
//{
//	if (avail > MAX_TERMS) {
//		fprintf(stderr, "항의 개수가 너무 많음\n");
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
//		case '>': 	// A의 차수 > B의 차수
//			attach(terms[As].coef, terms[As].expon);
//			As++;			break;
//		case '=': 	// A의 차수 == B의 차수
//			tempcoef = terms[As].coef + terms[Bs].coef;
//			if (tempcoef)
//				attach(tempcoef, terms[As].expon);
//			As++; Bs++;		break;
//		case '<': 	// A의 차수 < B의 차수
//			attach(terms[Bs].coef, terms[Bs].expon);
//			Bs++;			break;
//		}
//	// A의 나머지 항들을 이동함	
//	for (; As <= Ae; As++)
//		attach(terms[As].coef, terms[As].expon);
//	
//	// B의 나머지 항들을 이동함
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
//			printf(" 파일 열기 실패 \n");
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
////2장 연습문제 5번 이름(문자배열), 나이, 급여
//struct person
//{
//	char name[20];
//	int age;
//	float salary;
//};
////문제 6번 & 7번 복소수 구조체 및 복소수 더하기 함수
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
//// 2장 94페이지 퀴즈2번 이중포인터
//#include <stdio.h>
//typedef struct {
//	int x;
//	int y;
//}Point;
//void change_point(Point** ppa, Point** ppb) //이중포인터를 매개변수로 사용
//{
//	Point* tmp;
//	tmp = *ppa;
//	*ppa = *ppb;
//	*ppb = tmp;
//}
//void change_point00(Point* ppa, Point* ppb) // 포인터를 매개변수로 사용
//{
//	Point* tmp;
//	tmp = ppa;
//	ppa = ppb;
//	ppb = tmp;
//	printf("함수 안에서 변경\n");
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
//	printf("오리지날\n");
//	printf("%d %d %d %d\n", (*ppa).x, (*ppa).y, (*ppb).x, (*ppb).y);
//
//	//변수의 주소를 알려 주었을 때
//	change_point00(ppa, ppb);
//	printf("함수 change_point00 수행후 main에서 \n");
//	printf("%d %d %d %d\n", (*ppa).x, (*ppa).y, (*ppb).x, (*ppb).y);
//
//	//변수의 주소를 가지고 있는 변수의 주소를 알려 주었을 때
//	change_point(&ppa, &ppb);
//	printf("함수 change_point 수행후 main에서 \n");
//	printf("%d %d %d %d\n", (*ppa).x, (*ppa).y, (*ppb).x, (*ppb).y);
//	return 0;
//}