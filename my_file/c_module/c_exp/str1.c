#include<stdio.h>
#include<stdlib.h>

int add(int,int);
int sub(int,int);
int mul(int,int);
int division(int,int);

//typedef int (*operations)(int,int);
int (*f_ptr[100])(int,int);
int main(int argc , char *argv[])
{
	int num1;
	int num2;
	int result;
//	operations = f_ptr[100];
	char operator;
	
	operator = *argv[1];
	num1 = atoi(argv[2]);
	num2 = atoi(argv[3]);

	switch(operator)
	{
		case '+': f_ptr[0] = add;
				  result = (*f_ptr[0])(num1 , num2);
				  printf("%d\n", result);

		case '-': f_ptr[1] = sub;
                  result = (*f_ptr[1])(num1 , num2);
                  printf("%d\n", result);

		case '*': f_ptr[2] = mul;
                  result = (*f_ptr[2])(num1 , num2);
                  printf("%d\n", result);

		case '/': f_ptr[3] = division;
                  result = (*f_ptr[3])(num1 , num2);
                  printf("%d\n", result);
	}
	return 0;
}

int add(int a,int b)
{
	return (a+b);
}

int sub(int a, int b)
{
	return (a-b);
}

int mul(int a, int b)
{
	return (a*b);
}

int division(int a, int b)
{
	return (a/b);
}

