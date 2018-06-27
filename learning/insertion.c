#include <stdio.h>

int main( void )
{	
	int n = 5;
	int a[n] = {30, 25, 16, 5, 20};
	int temp;
	int i = 0;

/*	while(n){

		temp = a[i+1];
		while( (i >= 0) || temp > a[i]){

			if(temp < a[i]){
				a[i+1] = a[i];
				if( i == 0){
					a[i] = temp;
					}
				else
				   i--;
			}
			i++;			

		}
		n--;
	}*/
	while( 1 ){
	while( i >= 0)
	{
		temp = a[i+1];
		if( temp < a[i]){
			a[i+1] = a[i];
			}
			i--;
		}
		a[i+1] = temp;
	//	n--;
	}
	for( i = 0; i < 5; i++){
		printf("%d\t",a[i]);
		}

	return 0;
}
