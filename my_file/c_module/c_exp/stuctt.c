#include<stdio.h>
# pragma pack(1)
struct A {

	double d;
	char c;
}data;

struct M {

	int a:6;
	int d;
	char c;
	int b:4;

}s13;



int main(void)
{

	printf("%d\n",sizeof(data));
	
	printf("%d\n",sizeof(s13));
	return 0;
}
