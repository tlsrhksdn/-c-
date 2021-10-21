/*
첫번째 방법
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

	int num = 0; // 파일에서 읽은 bite를 수로 변환하기 위한 변수
	int index = -1; // coef 배열에 들어갈 인덱스를 의미
	for (int i = 0; ; i++) {
		if (buf[i] != ' ') {
			if (buf[i] == '\0') { // 파일의 마지막을 읽었으므로 마지막 수를 넣어준 후 반복문을 빠져나옴
				res.coef[index++] = num;
				break;
			}
			else { 
			// 문자열로 수를 받았으므로 int로 변환
			// ex) '5' 를 5로 받기 위해 '5'-'0' 해줌 (아스키코드)m
				num = num * 10 + (int)(buf[i] - '0');
			}
		}
		else {
			// 공백을 읽었을 때,
			if (index == -1) { // index 가 -1이라면 최대 차항을 읽었으므로 degree에 저장한다.
				res.degree = num;
				index++; // index 1 증가
			}
			else {
			// 계수를 의미하므로 index번째 num을 넣어주고 index를 1 증가시킴
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


//두번째 방법

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
	fp = fopen(filename, "r"); // 파일을 읽어서 파일 포인터에 대입.

	char buf[FILE_MAX]; // 읽은 파일의 bite를 저장하기 위한 배열

	memset(buf, 0, sizeof(buf)); // 배열 초기화, NULL 값으로 초기화한다.
	fgets(buf, sizeof(buf), fp); // 파일을 읽어서 buf 배열에 저장

	int num = 0; // 읽은 숫자를 저장하는 변수
	int index = 0; // 몇번째 숫자인지 표시하기위한 인덱스 변수
	for (int i = 0;  ; i++) {
		if (buf[i] == ' ' || buf[i] == '\0') { // 공백이거나 파일의 끝인경우
			// index / 2 를 해주는 이유는 
			// a b c d 에서 a*x^b + c*x^d 이므로 두개씩 짝을 이룬다.
			if (index & 1) { // 인덱스가 홀수라면 차수에 해당하는 수이므로
				terms[index / 2].expon = num; 
			}
			else { // 인덱스가 짝수라면 계수이므로 계수에 저장
				terms[index / 2].coef = num;
			}
			num = 0; // 다음 수를 받기위해 0으로 초기화
			index++; // 인덱스를 1 증가시킨다.
			if (buf[i] == '\0') { // 파일을 다 읽었다면 빠져나옴
				break;
			}
		}
		else {
			// 문자열로 수를 받았으므로 int로 변환
			// ex) '5' 를 5로 받기 위해 '5'-'0' 해줌 (아스키코드)
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
		fprintf(stderr, "항의 개수가 너무 많음\n");
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
