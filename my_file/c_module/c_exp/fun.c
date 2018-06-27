#include<stdio.h>

float func(f)
{
	float res;
	res = f * 1.2;
	return res;
}
	
int main(void)
{
	printf("%f\n",func(4.1));
}


