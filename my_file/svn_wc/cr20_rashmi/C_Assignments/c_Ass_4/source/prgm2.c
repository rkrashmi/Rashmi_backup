// program on Union

#include<stdio.h>
#include<string.h>

union sample
{
    int a :5;
    int b :10;
    int c :5;
    int d :21;
    int e;
};

int main(void)
{
    union sample data;
    data.e = 60;
    printf("sample data.e:%d\n",data.e);
    printf("sample data.a:%d\n",data.a);
    printf("sample data.b:%d\n",data.b);
    printf("sample data.c:%d\n",data.c);
    printf("sample data.d:%d\n",data.d);
	
	return 0;

}


