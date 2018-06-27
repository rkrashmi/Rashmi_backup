#include<stdio.h>
#include<string.h>
union sample
{
	int a :5;
	int b : 10;
	int c : 5;
	int d : 21;
	int e;
};
int main()
{
	union sample s;
	s.e = 60;
	printf("s.e:%d\n",s.e);
//	s.a = 5;
	printf("s.a:%d",s.a);
//	s.b = 10;
	printf("s.b:%d\n",s.b);
//	s.c = 5;
	printf("s.c:%d\n",s.c);
//	s.d = 21;
	printf("s.d:%d\n",s.d);
//	printf("s.e%d\n",s.e);
return 0;

}

