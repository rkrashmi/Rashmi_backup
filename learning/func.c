// function to check scope

#include <stdio.h>
int add (int ,int);

int main(void)
{
	int a = 10;
	int b = 20;
	int sum = 0;
	int res = 0;
	
	auto int add(int ,int);

	sum = add( a, b);

	 int add( int a , int b)
	{ 
		int res = 0;
		
		res = a + b;
		printf("In main = %d",res);
		return res;

	}

//	sum = add(a ,b);
	printf("sum = %d\n",sum);
//	printf("result from inside func = %d\n",res);

	return 0;
}




 int add (int a, int b)
{
	int S = 0;
	S = a + b + 2 + (3 * b);

	printf(" Outside main = %d\n", S);

	return S;
}
	
