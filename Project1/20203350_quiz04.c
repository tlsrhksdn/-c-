/*
//1번예제
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNING
#define MAX_DEGREE 101
#define MAX_FILE 1000
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_read(char *filename)
{
	FILE *fp;
	char buf[MAX_FILE];
	fp = fopen(filename, "rt");

	polynomial p;
	

	memset(buf, 0, sizeof(buf));
	fgets(buf, sizeof(buf), fp);

	int num = 0;
	int index = -1;
	for (int i = 0; ; i++)
	{
		if (buf[i] != ' ')
		{
			if (buf[i] == "\0")
			{
				p.coef[index++] = num;
				break;
			}
			else

		}
		else
		{
			if (index == -1)
			{
				p.degree = num;
				index++;
			}
			else
			{
				p.coef[index++] = num;
			}
			num = 0;
		}
	}
	fclose(fp);
	return p;
}
int main()
{
	poly_read("poly01.txt");
}

//2번예제
#include<stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNING
#define MAX_TERMS 101
#define FILE_MAX 1001
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];

polynomial poly_read(char *filename)
{
	FILE *fp;
	fp = fopen(filename, "rt");
	
	char buf[FILE_MAX];

	memset(buf, 0, sizeof(buf));
	fgets(buf, sizeof(buf), fp);

	int num = 0;
	int index = 0;
	for (int i = 0; ; i++)
	{
		if (buf[i] == ' ' || buf[i] == '\0')
		{
			if (index&i)
			{
				terms[index / 2].expon = num;
			}
			else
				terms[index / 2].coef = num;
			num = 0;
			index++;
			if (buf[i] == '\0')
				break;
		}
		else
			continue;
	}
	return p;
}*/