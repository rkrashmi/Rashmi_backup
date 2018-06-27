#include <stdio.h>

int main ( void )
{
#if 0
	//int x[5] = { 1, 2, 3, 4, 5};
	int x[] = { 1, 2, 3, 4, 5};
	char m[] = { '1', '2', '3', '4', '5'};
	int i,j;

	typeof (x) y[2];

//	y[0] = {56, 87, 543, 76, 654};
//	y[1] = {87, 543, 76, 654, 34};
y[0][0] = 23;

//	int b[10]={};
//	int x[5][5];

//	x[0] = {1, 2, 3, 4, 5};

/*	for(i = 0;i < 2; i++){
        for(j = 0; j < 5; j++){
	scanf("%d",&y[i][j]);}
	}*/
	printf("size of y = %d\n ", sizeof(y));
	printf("size of x = %d\n ", sizeof(x));
	printf("addr of y = %p\n", &y);
	printf("addr of x = %p\n", &x);

/*	for(i = 0;i < 2; i++){
		for(j = 0; j < 5; j++){
			printf("%d\t", *(&y[i] + j));
			}
			printf("\n");
 		}
*/
printf("%d\n",y[0][0]);
#endif


	int *x = NULL;
	int a = 20;

	typeof (x) y;

	y = &a;
	printf("address of a = %p\n", &a);
	printf("Address of a interms of y %p\n",y);

	return 0;
}	


























