/*
//5������
typedef struct {
	char name[100];
	int age;
	float monthly_fee;
}person;

//6������
typedef struct {
	float real;
	float imaginary;

}complex;

int main()
{
	complex c1;
	complex c2;
	return 0;
}

//7������
typedef struct {
	float real;
	float imaginary;
}Complex;

Complex complex_add(complex a, complex b)
{
	Complex c;
	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	return c;
}
*/