#include <stdio.h>
#if 0
int main ( void )
{
	int a = 0x12345678;
	char buf[4];
	char *ptr =(char *) &a;
	int i = 0;
	int *ptr1;
	for( i = 3; i >= 0; i--){
		buf[i] = *ptr;
//		printf("ptr = %d\n",*ptr);
		ptr++;
//		printf("ptr = %d\n",*ptr);
	}
	for( i = 0; i <= 3; i++){
	printf("%p\n",buf[i]);
	}

	/*while( i < 4 ){
		buf[i] = *(ptr + i);
		i++;
		printf("buf[%d] %d\n", i, buf[i]);
	}*/
	ptr1 = (int *)buf;
	printf("%p\n",ptr1);
	return 0;
}
#endif

#if 1
void func(){

}

int main(void)
{
	char (*ptr)(void);

	printf("%p\n %p\n", &ptr, &ptr + 1);
	printf("%p\n%p\n", func, func + 1);
	getchar();
}
#endif
