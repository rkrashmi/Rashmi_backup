#include <stdio.h>
int main()
{
#if 0
	char str1[10];
	char *str2 = "hellohjiy";
	int i;

	printf("str1 = %d\n",sizeof(str1));
	printf("Enter the array elments\n");
	for( i = 0; i < 13; i++) 
	scanf("%d" ,&str1[i]);
	
	printf("str2 = %d\n",sizeof(str2));

	for( i = 0; i < 13; i++) 
	printf("array elements are: %d\n", str1[i]);
	printf("%s\n", str2);
	return 0;
}

	char a[2] = "hii tsjdgfjkl";
	printf("%s",a);
	return 0;
}
#endif
	int b[3] = {1,4 ,10};
	int *p;
	p = b;
	printf("%p\n",b);
	printf("%p\n",p);

	p++;
//`	b++;

	printf("%p\n",*p);
	p++;
	printf("%p\n",*p);
	
	p++;
	
	printf("%p\n",*p);
	return 0;
}
