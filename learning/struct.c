#include<stdio.h>
#include <string.h>

struct tag{

	int a: 5;
	int b:6;
	int c:6;
	int buf[];
};

int main()
{
	struct tag s1,s2;

	s1.a = 22;
	s1.b = 17;
	s1.c = 14;

	printf("%d\t%d\t%d\n", s1.a,s1.b,s1.c);
	s2.a = 1;
	s2.b = 2;
	s2.c = 3;
	
	printf("%d\n%d\n%d\n",s2.a,s2.b,s2.c);

	strcpy(s1.buf,"555555");
	printf("%d\n",s1.buf);
	printf("%d\n%d\n%d\n",s2.a,s2.b,s2.c);
	return 0;

}
