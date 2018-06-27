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

    typedef int (*op)(int,int);
	op array[10];
    
	operator = *argv[1];
    operand1 = my_atoi(argv[2]);
    operand2 = my_atoi(argv[3]);

	array[0] = &add;
	array[1] = &sub;
	array[2] = &mul;
	array[3] = &division;

	switch(operator)
    {

    case 'a': result = (array[0])(operand1,operand2);
              printf("sum = %d\n",result);
              break;

    case 's': result = (array[1])(operand1,operand2);
              printf("Subtraction = %d\n",result);
              break;

    case 'm': result = (array[2])(operand1,operand2);
              printf("Multiplication = %d\n",result);
              break;

    case 'd': result = (array[3])(operand1,operand2);
              printf("Division = %d\n",result);
              break;
    }
    return 0;
}
                
