/*스택 ADT
객체:0개 이상의 원소를 가지는 유한 선형 리스트
연산
create(size):최대 크기가 size인 공백 스택을 생성한다
is_full(s):
	if(스택의 원소수==size) return TRUE;
	else return FALSE;
is_empty(s):
	if(스택의 원소수==0) return TRUE;
	else return FALSE;
push(s,item):
	if(is_full(s)) return ERROR_STACKFULL;
	else 스택의 맨 위에 item을 추가한다
pop(s):
	if(is_empty(s)) return ERROR_STACKEMPTY;
	else 스택의 맨 위의 원소를 제거해서 반환한다.
peek(s):
	if(is_empty(s)) return ERROR_STACKEMPTY;
	else 스택의 맨 위의 원소를 제거하지 않고 반환한다.
*/
////프로그램 4.1 
////정수 배열 스텍 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//
//#define max_stack_size 100
//typedef int element;
//element stack[max_stack_size];
//int top = -1;
//
//int is_empty()
//{
//	return (top == -1);
//}
//
//int is_full()
//{
//	return (top == (max_stack_size - 1));
//}
//
//void push(element item)
//{
//	if (is_full())
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//
//	else stack[++top] = item;
//}
//element pop()
//{
//	if (is_empty())
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return stack[top--];
//}
//element peek()
//{
//	if (is_empty())
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return stack[top];
//}
//int main()
//{
//	push(1);
//	push(2);
//	push(3);
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	printf("%d\n", pop());
//	
//}
////프로그램 4.2
////스택의 요소를 구조체로 하기
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 100
//#define MAX_STRING 100
//
//typedef struct {
//	int student_no;
//	char name[MAX_STRING];
//	char address[MAX_STRING];
//}element;
//
//element stack[MAX_STACK_SIZE];
//int top = -1;
//
//int is_empty()
//{
//	return (top == -1);
//}
//
//int is_full()
//{
//	return (top == (MAX_STACK_SIZE - 1));
//}
//
//void push(element item)
//{
//	if (is_full())
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//
//	else stack[++top] = item;
//}
//element pop()
//{
//	if (is_empty())
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return stack[top--];
//}
//element peek()
//{
//	if (is_empty())
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return stack[top];
//}
//int main()
//{
//	element ie = { 20190001,"Hong","Seoul" };
//	element oe;
//
//	push(ie);
//	oe = pop();
//
//	printf("학번:%d\n", oe.student_no);
//	printf("이름:%s\n", oe.name);
//	printf("주소:%s\n", oe.address);
//}

//4-3,일반적인 배열 스택 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//void init_stack(StackType *s)
//{
//	s->top = -1;
//}
//
//int is_empty(StackType *s)
//{
//	return (s->top = -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		fprintf(stderr, "스택 포함 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s)) {
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//int main()
//{
//	StackType s;
//
//	init_stack(&s);
//	push(&s, 1);
//	push(&s, 2);
//	push(&s, 3);
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//}

////프로그램 4.5
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//typedef struct {
//	element *data;
//	int capacity;
//	int top;
//}StackType;
//
//void init_stack(StackType *s)
//{
//	s->top = -1;
//	s->capacity = 1;
//	s->data = (element*)malloc(s->capacity * sizeof(element));
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (s->capacity - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		s->capacity *= 2;
//		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
//	}
//	s->data[++(s->top)] = item;
//
//}
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//int main(void)
//{
//	StackType s;
//	init_stack(&s);
//	push(&s, 1);
//	push(&s, 2);
//	push(&s, 3);
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	printf("%d\n", pop(&s));
//	feee(s->data);
//	return 0;
//
//
//}

////괄호 검사 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//
//typedef struct {
//	element data[MAX_STACK_SIZE];    
//	int top;
//}StackType;
//
//
//void init_stack(StackType *s)
//{
//	s->top == -1;
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 -'''''''''''''''''''''''''''''''''''''''''''''''에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//int check_matching(const char *in)
//{
//	StackType s;
//	char ch, open_ch;
//	int i, n = strlen(in);
//	init_stack(&s);
//
//	for (int i = 0; i < n; i++)
//	{
//		ch = in[i];
//		switch (ch)
//		{
//		case '(': case'[': case '{':
//			push(&s, ch);
//			break;
//		case ')': case '}': case ']':
//			if (is_empty(&s))
//				return 0;
//			else
//			{
//				open_ch = pop(&s);
//				if ((open_ch == '('&&ch != ')') ||
//					(open_ch == '{'&&ch != '}') ||
//					(open_ch == '['&&ch != ']'))
//					return 0;
//			}
//			break;
//		}
//	}
//	if (!is_empty(&s)) return 0;
//	return 1;
//}
//
//int main()
//{
//	char *p = "{A[(i+1)]=0;}";
//	if (check_matching(p) == 1)
//		printf("%s 괄호검사성공\n", p);
//	else
//		printf("%s 괄호검사실패\n", p);
//	return 0;
//}

//후위 연산자 계산 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//void init_stack(StackType *s)
//{
//	s->top == -1;
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 -'''''''''''''''''''''''''''''''''''''''''''''''에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//
//int eval(char exp[])
//{
//	int op1, op2, value, i = 0;
//	int len = strlen(exp);
//	char ch;
//	   
//	StackType s;
//
//	init_stack(&s);
//	for (i = 0; i < len; i++)
//	{
//		ch = exp[i];
//		if (ch != '+'&&ch != '-'&&ch != '*'&&ch != '/')
//		{
//			value = ch - '0';  //입력이 피연산자가 아니면==>정수로 바꿔준다.
//			push(&s, value);
//		}
//		else {
//			op2 = pop(&s);  //스텍의 특징 생각
//			op1 = pop(&s);
//			switch (ch) {
//			case '+': push(&s, op1 + op2); break;
//			case '-': push(&s, op1 - op2); break;
//			case '*': push(&s, op1 * op2); break;
//			case '/': push(&s, op1 / op2); break;			
//			}
//		}
//	}
//	return pop(&s);
//}
//int main()
//{
//	int result;
//	printf()
//}

////중위 표기 수식을 후위 표기 수식으로 변환하는 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//void init_stack(StackType *s)
//{
//	s->top == -1;
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 -'''''''''''''''''''''''''''''''''''''''''''''''에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//int prec(char op)
//{
//	switch (op) {
//	case '(': case ')': return 0;
//	case '*': case '/': return 1;
//	case '+': case '-': return 2;
//	}
//	return -1;
//}
//void infix_to_postfix(char exp[])
//{
//	int i = 0;
//	char ch, top_op;
//	int len = strlen(exp);
//	StackType s;
//	init_stack(&s);
//	for (i = 0; i < len; i++)
//	{
//		ch = exp[i];
//		switch (ch) {
//		case'+': case'-': case '*': case '/':
//			whlie(!is_empty(&s) && (prec(ch) <= prec(peek(&s))) {
//				printf("%c", pop(&s));
//			}
//			push(&s, ch);
//			break;
//		case '(':
//			push(&s, ch);
//			break;
//		case ')':
//			top_op = pop(&s);
//			while (top_op != '(') {
//				printf("%c", top_op);
//				top_op = pop(&s);
//			}
//			break;
//		default:
//			printf("c", ch);
//			break;
//		}
//	}
//	while (!is_empty(&s))
//		printf("%c", pop(&s));
//}
//int main()
//{
//	char *s = "(2+3)*4+9";
//	printf("중위표기수식 %s\n", s);
//	printf("후위표기수식 ");
//	intix_to_postfix(s);
//	printf("\n");
//	return 0;
//}

////4-9.미로탐색 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include"stack.h"
//#define MAZE_SIZE 6
//
//
//element here = { 1,0 }, entry = { 1,0 };
//
//char maze[MAZE_SIZE][MAZE_SIZE] = {
//	{'1','1','1','1','1','1' },
//{'e','0','1','0','0','1'},
//{'1','0','0','0','1','1'},
//{'1','0','1','0','1','1'},
//{'1','0','1','0','0','x'},
//{'1','1','1','1','1','1'}
//};
//void push_loc(StackType*s, int r, int c)
//{
//	if (r < 0 || c < 0) return;
//	if (maze[r][c] = '1' && maze[r][c] != '.') {
//		element tmp;
//		tmp.r = r;
//		tmp.c = c;
//		push(s, tmp);
//	}
//}
//void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
//{
//	printf("\n");
//	for (int r = 0; r < MAZE_SIZE; r++)
//	{
//		for (int c = 0; c < MAZE_SIZE; c++)
//			printf("%c", maze[r][c]);
//		printf("\n");
//	}
//}
//int main(void)
//{
//	int r, c;
//	StackType s;
//	init_stack(&s);
//	here = entry;
//
//	while (maze[here.r][here.c] != 'x') {
//		r = here.r;
//		c = here.c;
//		maze[r][c] = '.';
//		maze_print(maze);
//		push_loc(&s, r - 1, c);
//		push_loc(&s, r + 1, c);
//		push_loc(&s, r, c - 1);
//		push_loc(&s, r, c + 1);
//		if (is_empty(&s))
//		{
//			printf("실패\n");
//			return;
//		}
//		else
//			here = pop(&s);
//	}
//	printf("성공\n");
//	return 0;
//}


////다항식 덧셈 프로그램_2+p.83 quiz_2번째방법
//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_TERMS 101
//typedef struct {
//	float coef; 
//	int expon;
//}polynomial;
//polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
//int avail = 6;
//
//char compare(int a, int b)
//{
//	if (a > b) return '>';
//	else if (a == b) return '=';
//	else return '<';
//}
//void attach(float coef, int expon)
//{
//	if (avail > MAX_TERMS)
//	{
//		fprintf(stderr, "항의 개수가 너무 많음");
//		exit(1);
//	}
//	terms[avail].coef = coef;
//	terms[avail].expon = expon;
//	avail++;
//}
//void poly_add1(int As, int Ae, int Bs, int Be, int *Cs, int*Ce)
////As,Ae:다항식 A의 처음과 끝
////Bs,Be:다항식 B의 처음과 끝
////Cs,Ce:덧셈의 결과로 생성되는 다함식의 처음과 끝
//{
//	float tempcoef;
//	int avail;
//	while (As <= Ae &&Bs <= Be)
//	{
//		switch (compare(terms[As].expon, terms[Bs].expon))
//		{
//		case '>':
//			attach(terms[As].coef, terms[As].expon);
//			As++; break;
//		case '=':
//			tempcoef = terms[As].expon + terms[Bs].expon;
//			if (tempcoef)
//				attach(terms[As].coef, terms[As].expon);
//			As++; Bs++; break;
//		case'<':
//			attach(terms[Bs].coef, terms[Bs].expon);
//			Bs++; break;
//		}
//	}
//	for (; As <= Ae; As++)
//		attach(terms[As].coef, terms[As].expon);
//	for (; Bs < -Be; Bs++)
//		attatch(terms[Bs].coef, terms[Bs].expon);
//	*Ce = avail - 1;
//}
//void print_poly(int s, int e)
//{
//	for (int i = s; i < e; i++)
//		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
//	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
//}
//void poly_read(polynomial *terms)
//{
//	int i = 0;
//	FILE *fp;
//	errno_t err;
//	err = fopen_s(&fp, "poly02.txt", "rt");
//	if (NULL != fp)
//	{
//		while (EOF != fscanf_s(&fp, "&f &d", &terms[i].coef, &terms[i].expon))
//			i++;
//		fclose(fp);
//	}
//	else
//		printf("파일 열기 실패\n");
//}
//int main()


////3-2.다항식 덧셈 프로그램(1)+p.83 quiz_1번째방법
//
//#include<stdio.h>
//#define MAX(a,b) (((a)>(b)) ? (a):(b))
//#define MAX_DEGREE 101
//typedef struct {
//	int degree;
//	float coef[MAX_DEGREE];
//}polynomial;
//
//polynomial poly_add1(polynomial A, polynomial B)
//{
//	polynomial C;
//	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수
//	int degree_a = A.degree; 
//	int degree_b = B.degree;
//	C.degree = MAX(A.degree, B.degree);
//
//	while (Apos <= A.degree &&Bpos <= B.degree)
//	{
//		if (degree_a > degree_b)
//		{
//			C.coef[Cpos++] = A.coef[Apos++];
//			degree_a--;
//		}
//		else if (degree_b > degree_a)
//		{
//			C.coef[Cpos++] = B.coef[Bpos++];
//			degree_b--;
//		}
//		else
//		{
//			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
//			degree_a--;
//			degree_b--;
//		}
//	}
//	return C;
//}
//void print_poly(polynomial p)
//{
//	for (int i = p.degree; i > 0; i--)
//		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
//	printf("%3.1f \n", p.coef[p.degree]);
//}
//void  poly_read(polynomial *a, polynomial *b)
//{
//	int i;
//	FILE *fp;
//	errno_t err;
//	err = fopen_s(&fp, "poly01.txt", "rt");
//	if (NULL != fp)
//	{
//		fscanf_s(fp, "%d", &(*a).degree);
//		for (i = 0; i <= (*a).degree; i++)
//			fscanf_s(fp, "%f", &(*b).coef[i]);
//
//		fscanf_s(fp, "%d", &(*a).degree);
//		for (i = 0; i <= (*a).degree; i++)
//			fscanf_s(fp, "%f", &(*b).coef[i]);
//
//		fclose(fp);
//	}
//	else
//		printf("파일 열기 실패\n");
//}
//int main()
//{
//	polynomial a = { 5,{3,6,0,0,0,10} };
//	polynomial b = { 4,{7,0,5,0,1} };
//	polynomial c;
//
//	print_poly(a);
//	print_poly(b);
//	c = poly_add1(a, b);
//	printf("-------------------------------------------");
//	print_poly(c);
//	return 0;
//}
//

////3-4.행렬 전치 프로그램
//#include<stdio.h>
//#define ROWS 3
//#define COWS 3
//
//void matrix_transpose(int A[ROWS][COWS], int B[ROWS][COWS])
//{
//	for (int r = 0; r < ROWS; r++)
//		for (int c = 0; c < COWS; c++)
//			B[c][r] = A[r][c];
//}
//void matrix_print(int A[ROWS][COWS])
//{
//	printf("=============================\n");
//	for (int r = 0; r < ROWS; r++) {
//		for (int c = 0; c < COWS; c++)
//			prrintf("%d", A[r][c]);
//		printf("\n");
//	}
//	printf("=============================\n");
//}
//int main()
//{
//	int array1[ROWS][COWS] = { {2,3,0},{8,9,1},{7,0,5} };
//	int array2[ROWS][COWS];
//	matrix_transpose(array1, array2);
//	matrix_print(array1);
//	maxrix_print(array2);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_TERMS 100
//
//typedef struct {
//	int row;
//	int col;
//	int value;
//}element;
//
//typedef struct SparseMatrix {
//	element data[MAX_TERMS];
//	int rows;
//	int cols;
//	int terms; //항의 개수
//}SparseMatrix;
//
//SparseMatrix matrix_transpose2(SparseMatrix a)
//{
//	SparseMatrix b;
//
//	int bindex;
//	b.rows = a.rows;
//	b.cols = a.cols;
//	b.terms = a.terms;
//
//	if (a.terms > 0) {
//		bindex = 0;
//		for (int c = 0; c < a.cols; c++) {
//			for (int i = 0; i < a.terms; i++) {
//				if (a.data[i].col == c) {
//					b.data[bindex].row = a.data[i].col;
//					b.data[bindex].col = a.data[i].row;
//					b.data[bindex].value = a.data[i].value;
//					bindex++;
//				}
//			}
//		}
//	}
//	return b;
//}
//
//void matrix_print(SparseMatrix a)
//{
//	printf("======================\n");
//	for (int i = 0; i < a.terms; i++)
//	{
//		printf("(%d,%d,%d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
//	}
//	printf("======================\n")
//}
//int main()
//{
//	SparseMatrix m = {
//		{{0,3,7,},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},6,6,7
//	};
//	SparseMatrix result;
//
//	result = matrix_transpose2(m);
//	matrrix_print(result);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//
//typedef struct {
//	element *data;
//	int top;
//	int capacity;
//}StackType;
//
//void init_stack(StackType *s)
//{
//	s->top = -1;
//	s->capacity = 1;
//	s->data = (element*)malloc(s->capacity * sizeof(element));
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (s->capacity - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s)) {
//		s->capacity *= 2;
//		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
//	}
//	s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s)) {
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}

////4-6.괄호 검사 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//void init_stack(StackType *s)
//{
//	s->top = -1;
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//int check_matching(const char *in)
//{
//	StackType s;
//	char ch, open_ch;
//	int i, n = strlen(in);
//	init_stack(&s);
//
//	for (i = 0; i < n; i++)
//	{
//		ch = in[i];
//		switch (ch) {
//		case '(': case'{':case '[':
//			push(&s, ch);
//			break;
//		case ')': case '}': case ']':
//			if (is_empty(&s)) return 0;
//			else
//			{
//				open_ch = pop(&s);
//				if ((open_ch == '('&&ch != ')') ||
//					(open_ch == '{'&&ch != '}') ||
//					(open_ch == '['&&ch != ']'))
//					return 0;
//			}
//			break;
//		}
//	}
//	if (!is_empty(&s)) return 0;
//	return 1;
//}

////프로그램 4-7.후위표기식 계산
//
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//void init_stack(StackType *s)
//{
//	s->top = -1;
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//
//int eval(char exp[])
//{
//	int op1, op2, i, value;
//	int len = strlen(exp);
//	char ch;
//	StackType s;
//
//	init_stack(&s);
//	for (int i = 0; i < len; i++)
//	{
//		ch = exp[i];
//		if (ch != '+'&&ch != '-'&&ch != "*"&&ch != '/')
//		{
//			value = ch - '0';  //문자를 정수로 변환
//			push(&s, value);
//		}
//		else
//		{
//			op2 = pop(&s);
//			op1 = pop(&s);
//			switch (ch) {
//			case '+': push(&s, op1 + op2); break;
//			case '-': push(&s, op1 -op2); break;
//			case '*': push(&s, op1 * op2); break;
//			case '/': push(&s, op1 / op2); break;
//			}
//		}
//	}
//	return pop(&s);
//}

////4-8.중위 표기 수식을 후위 표기 수식으로 변환하는 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//void init_stack(StackType *s)
//{
//	s->top = -1;
//}
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//int is_full(StackType *s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//
//int prec(char op)
//{
//	switch (op) {
//	case '(': case ')': return 0;  //우선도가 높을수록 낮은 숫자 부여
//	case '+': case '-': return 1;
//	case '*': case '/': return 2;
//	}
//	return -1;
//}
//void infix_to_postfix(char exp[])
//{
//	int i = 0;
//	char ch, top_op;
//	int len = strlen(exp);
//	StackType s;
//
//	init_stack(&s);
//	for (i = 0; i < len; i ++) {
//		ch = exp[i];
//		switch (ch) {
//		case '+': case '-': case'*': case '/':
//			while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
//				printf("%c", pop(&s));
//			push(&s, ch);
//			break;
//		case '(':
//			push(&s, ch);
//			break;
//		}
//	}
//}


//5-5.은행 서비스 시뮬레이션 프로그램
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_QUEUE_SIZE 10
//typedef struct {
//	int id;
//	int arrival_time;
//	int service_time;
//}element;
//
//typedef struct {
//	int front, rear;
//	element data[MAX_QUEUE_SIZE];
//}QueueType;
//
//void error(char *message)
//{
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType *q)
//{
//	q->front = q->rear = 0;
//}
//int is_empty(QueueType *q)
//{
//	return(q->front == q->rear);
//}
//int is_full(QueueType *q)
//{
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//void queue_print(QueueType *q)
//{
//	printf("QUEUE(front= %d rear= %d)=", q->front, q->rear);
//	if (!is_empty)
//	{
//		int i = q -> front;
//		do {
//			i = (i + 1) % MAX_QUEUE_SIZE;
//			if (i == q->rear)
//				break;
//		} while (i != q->front);
//	}
//	printf("\n");
//}
//void enqueue(QueueType *q,element item)
//{
//	if (is_full(q))
//		error("스택 포화상태입니다.");
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	item = q->data[q->rear];
//}
//element dequeue(QueueType *q)
//{
//	if (is_empty(q))
//		error("스택 공백상태입니다.");
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	return q->data[q->front];
//}
//element peek(QueueType *q)
//{
//	if (is_empty(q))
//		error("스택 공백상태입니다.");
//	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
//}
//
//int main(void)
//{
//	int minutes = 60;
//	int total_wait = 0;
//	int total_customers = 0;
//	int service_time = 0;
//	int service_customer;
//	QueueType queue;
//	init_queue(&queue);
//
//	srand(time(NULL));
//	for (int clock = 0; clock < minutes; clock++)
//	{
//		printf("현재시각=%d\n", clock);
//		if ((rand() % 10) < 3) {
//			element customer;
//			customer.id = total_customers++;
//			customer.arrival_time = clock;
//			customer.service_time = rand() % 3 + 1;
//			enqueue(&queue, customer);
//			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n", customer.id, customer.arrival_time, customer, service_time);
//		}
//		if (service_time > 0)
//		{
//			printf("고객 %d 업무처리중입니다.\n", service_customer);
//			service_time--;
//		}
//		else {
//			if (!is_empty(&queue)) {
//				element customer = dequeue(&queue);
//				service_customer = customer.id;
//				service_time = customer.service_time;
//				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
//				total_wait += clock - customer.arrival_time;
//			}
//		}
//	}
//
//	printf("전체 대기 시간=%d분 \n", total_wait);
//}
//
