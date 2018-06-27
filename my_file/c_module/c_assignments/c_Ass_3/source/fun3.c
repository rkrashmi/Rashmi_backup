#include<stdio.h>
#include<stdlib.h>

int add(int a , int b)
{
    return(a+b);
}

int sub(int a , int b)
{
    return(a-b);
}

int mul(int a , int b)
{
    return(a * b);
}

int division(int a , int b)
{
    return(a/b);
}

int main(int argc, char *argv[])
{
	int result;
	int operand1;
	int operand2;
	char operator;
	
	int (*a_op)(int,int);
	int (*s_op)(int,int);
	int (*m_op)(int,int);
	int (*d_op)(int,int);

	operator = *argv[1];
	operand1 = my_atoi(argv[2]);
	operand2 = my_atoi(argv[3]);

	a_op = &add;
	s_op = &sub;
	m_op = &mul;
	d_op = &division; 

	switch(operator)
	{
	
	case 'a': result = (*a_op)(operand1,operand2);
			  printf("sum = %d\n",result);
			  break;

	case 's': result = (*s_op)(operand1,operand2);
			  printf("Subtraction = %d\n",result);
			  break;

	case 'm': result = (*m_op)(operand1,operand2);
              printf("Multiplication = %d\n",result);
              break;

	case 'd': result = (*d_op)(operand1,operand2);
              printf("Division = %d\n",result);
              break;
	}
	return 0;
}   
