
#if 0
#include<stdio.h>
#include<stdlib.h>
    enum weekdays{ Monday = 7, Tuesday, Wednesday};
int main()
{
//	int a;
//	enum weekdays{ Monday = 7, Tuesday, Wednesday};
	
//	e.Monday = 7;
//	8 = a;
//	Monday = 8;
//	printf("monday : %d\n", Tuesday);
	
	return 0;
}

#endif

#include<stdio.h>
/*	const int var = 10;
	 enum tag{
		a= var,
		b
	};

	int main(void)
	{
		printf("%d\n",a);
		return 0;
	}*/
/*
int main ()

{

	int num;

	char *str = "Global edge";
	printf("%x\n",str);
	printf ("0x%08x\n","Global edge");

	printf ("%s\n","Global edge");

	num = printf ("%x\n","Global edge");
	 printf ("%d\n", num);

	num = printf ("%s\n","Globaledge");

	printf ("%d\n", num);

	return 0;

}*/
/*
void fun (char *s)

{

	printf ("0x%08x\n", s);

	return ;

}



 int main ()

{

	fun("Some people are not worth for trust");

	return 0;

}*/
/*
 int main ()

{

	char amsg[] = "Global";

	char *pmsg = "edge";



	printf ("%p\n",amsg);

	printf ("%p\n",pmsg);

	printf ("%s\n",amsg);

	printf ("%p\n",*pmsg);

	printf ("%s\n", *pmsg);



	return 0;

}*/
/*
int main ()

{

	char msg[] = "hi";

	char dmsg[3];

//	dmsg = msg;

	char *pmsg = "Hello";

	char *pdmsg;

	pdmsg = pmsg;



	printf ("%p\n", pmsg);

	printf ("%p\n", pdmsg);

	printf ("%s\n", pmsg);

	printf ("%p\n", *msg);



	return 0;

}*/
/*
char *n = "hai";


int main ()

{
	//char *n;
	char *p = "Higlobal";

	char s[8] = "Hello";

//	p = &s[0];

	printf ("%p\n",p);

	printf ("%p\n",&s);

//	*p = 'p';

	printf ("%d\n",*p);

	p = p + 8;

	printf ("%p\n",p);

//	*p = 0;

	printf ("%p\n",n);

	//p = n;

	*p = n;

	printf ("%p\n",p);

//	printf ("%c\n", s[0]);



	return 0;

}*/
/*
int main ()

{

	int a = 10;

	int b = &a;

	printf ("1 = %p\n", &a);

	printf ("2 = %08x\n", b);

	printf ("3 = %p\n", b);

	return 0;

}

int main()

{

	int *p = 20;
	printf ("p = %d\n", p);
	p++;

	printf ("p = %d\n", p);

	return 0;

}*/

int main ()

{

	char *a[4] = {"global","edge","soft","limited"};

	printf ("1= %s\n",*(a+1));

	printf ("2 = %c\n",(*(*a + 1)));

	printf ("3 = %p\n",a+1);

	return 0;

}
