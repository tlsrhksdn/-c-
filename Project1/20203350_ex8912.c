//8번 문제
#include<stdio.h>
#include<string.h>
#define n 100
void insert(int array[],int loc,int value)
{
	
	array[loc] = value;
	memmove(array + 1, array, sizeof(int)*(n - 1));
}
int main()
{
	int array[n] = { 0,0,0,0,1,2 ,};
	insert(array, 3, 5);
	for (int i = 0; i < n; i++)
	{
		printf("%d", array[i]);
	}
	return 0;
}



//9번 문제
//O(n)


//12번 문제
#include<stdio.h>
typedef struct {
	int num;
	char ch[20];
}question_12;
int main(void)
{
	question_12 *s;
	
	s = (question_12*)malloc(sizeof(question_12));
	if (s == NULL)
	{
		fprintf(stderr,"%s\n", "스택 공백 에러");
		exit(1);
	}
	s->num = 100;
	strcpy(s->ch, "just testing");
	printf("%d", s->num);
	printf("%s", s->ch);
	free(s);
	return 0;
}
