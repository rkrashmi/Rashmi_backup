#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#if 0
double avg(int num, ...)
{
	va_list arguments;
	double sum = 0;
	int x;
	va_start(arguments,num);

	for(x = 0; x < num; x++)
	{	
		sum += va_arg(arguments,double);
//	printf("list = %f\n",va_arg(arguments,double));
	}
	va_end(arguments);

	return (sum/num);
}
#endif
double avg(int x, ...);
int main()
{
//	va_list arguments;
	printf("%f\n",avg(3,(double)11,(double)16,(double)17));
//	printf("%f\n",va_arg);
	printf("%f\n",avg(5,0.71,15.2,11.6,7.8,16.2));
//	 printf("%f\n",va_arg(arguments,double));

	return 0;
}

double avg(int num, ...)
{
    va_list arguments;
    double sum = 0;
    int x;
    va_start(arguments,num);

    for(x = 0; x < num; x++)
    {
        sum += va_arg(arguments,double);
		printf("%f\n",sum);
//  printf("list = %f\n",va_arg(arguments,double));
    }
    va_end(arguments);

    return (sum/num);
}

