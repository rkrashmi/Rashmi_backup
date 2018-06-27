
#include  <stdio.h>
#if 0

 union tag {
         unsigned int value;
         struct {
                 unsigned char one   : 8;
                 unsigned char two   : 8;
                 unsigned char three : 8;
                 unsigned char four  : 8;
         } bit_field;
 };

 int main( void ) {

         union tag var = {0x1A1B1C1D};
         unsigned char *ptr = (unsigned char *)(&var);

         printf("The entire hex value is 0x%X\n", var.value);
         printf("The first byte is 0x %X @ %p\n", *(ptr + 0), ptr + 0);
         printf("The second byte is 0x %X @ %p\n", *(ptr + 1), ptr + 1);
         printf("The third byte is 0x %X @ %p\n", *(ptr + 2), ptr + 2);
         printf("The fourth byte is 0x %X @ %p\n", *(ptr + 3), ptr + 3);
}
#endif
#if 0
/** Max of 3 */

int main()
{
	int a;
	int b;
	int c;

	printf ("enter three num\n");
	scanf ("%d %d %d", &a,&b,&c);

	(a > b && (a > c && printf("a is big:%d\n", a) ||printf("c is big:%d\n", c) )) || (b > c && printf("b is big:%d\n", b) ||printf("c is big:%d\n", c) );

	return 0;
}
#endif

#if 0
/* function pointer ***/

#include <stdio.h>

int main ()
{
    int (*fun)(const char *, ...);

    fun = printf;

    fun("My name is Ganesh\n");

    return 0;
}
#endif

#if 1

int main()
{
	static int a[]={10,20,30,40,50};
	static int *p[]={a,a+3,a+4,a+1,a+2};
	int **ptr=p;
	ptr++;
	printf("%d %d",*ptr - *p,**ptr);
	return 0;
}
#endif
