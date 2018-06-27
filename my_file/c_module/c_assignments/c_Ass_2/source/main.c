// main function of all expeiments

#include"header.h"

int main(void)
{
#if 0
	char *buf = NULL;
	char *sbuf = NULL;
	char *dbuf = NULL;
	int n;
	int count;
	int pos;
	int choice;
	char ch;
	
	printf("Enter the experiment number :");
	printf("1.Copy n characters from one buffer to another\n");
	printf("2.To append a string to another string\n");
	printf("3.To append n characters of a string to another string\n");
	printf("4.Compare two strings\n");
	printf("7.To reverse a given string\n");
	printf("8.To squeeze the consecutive similar characters from a string\n");
	printf("9.To check whether a given string is rotated string of other or not\n");
	printf("11.Insert a char in a given string\n");
	printf("12.To check occurenace of three 1's in a given array\n");

	if(NULL == (buf  = (char *) malloc (sizeof(char)* MAX))){
    	perror("malloc failed\n");
        exit(EXIT_FAILURE);
       }

	if(NULL == (fgets(buf,MAX,stdin))) {
        perror("fgets failed");
        exit(EXIT_FAILURE);
       }
	choice = my_atoi(buf);

	switch(choice)
	{
		case 1:	{
#endif
			//	sbuf = "Global Edge";
	char a[10] = "hello";
	char b[1];
				/*printf("Enter the n characters to copy\n");
				if(NULL == (buf  = (char *) malloc (sizeof(char)* MAX))){
			        perror("malloc failed\n");
			        exit(EXIT_FAILURE);
      			 }

			    if(NULL == (fgets(buf,MAX,stdin))) {
       				 perror("fgets failed");
       				 exit(EXIT_FAILURE);
       		     }
				 n = my_atoi(buf);*/
		
				// my_strncpy( sbuf, dbuf, n);
				strcpy(b,a);
				 printf("b");
				 }
				 //break;
#if 0
		case 2:	printf("Enter the first string:\n");
				 if(NULL == (sbuf  = (char *) malloc (sizeof(char)* MAX))){
       				 perror("malloc failed\n");
			         exit(EXIT_FAILURE);
       			}

    			if(NULL == (fgets(sbuf,MAX,stdin))) {
       				 perror("fgets failed");
        			 exit(EXIT_FAILURE);
      			 }
				
				printf("Enter the first string:\n");
                 if(NULL == (dbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(dbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }
			
				sappend( sbuf, dbuf);
				printf("Output = %s\n", dbuf);
				break;



		case 3:	printf("Enter the first string:\n");
                 if(NULL == (sbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(sbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }

                printf("Enter the second string:\n");
                 if(NULL == (dbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(dbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }

				 printf("Enter the n characters to copy\n");
                 if(NULL == (buf  = (char *) malloc (sizeof(char)* MAX))){
                    perror("malloc failed\n");
                    exit(EXIT_FAILURE);
                     }

                 if(NULL == (fgets(buf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                    }
                n = my_atoi(buf);

			    snappend(sbuf, dbuf, n);
				printf("Output = %s\n",dbuf);
				break;

		case 4:	printf("Enter the first string:\n");
                 if(NULL == (sbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(sbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }

                printf("Enter the second string:\n");
                 if(NULL == (dbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(dbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }

				n = my_strcmp( sbuf, dbuf);
				if(n == 0)
					printf("Two strings are equal\n");
				else if(n > 0)
					printf("sbuf is greater than dbuf\n");
				else if(n < 0)
					printf("dbuf is greater than sbuf\n");
				break;

		case 5: {
			//	const char *sbuf;
			//	const char *dbuf;
				 printf("Enter the first string:\n");
                 if(NULL == (sbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(sbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }

                printf("Enter the second string:\n");
                 if(NULL == (dbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(dbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }

			    count = strspn(sbuf , dbuf);
				printf("initial set of characters = %p",count);
				}
				break;

		case 7:	 printf("Enter the string:\n");
                 if(NULL == (sbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(sbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }

				reverse(sbuf);
				printf("Reversed string is = %s\n",dbuf);
				break;

/*		case 8:	printf("Enter the string:\n");
                if(NULL == (sbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(sbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }
				
				dbuf = squeeze(sbuf);
				printf("output after squeezing = %s",dbuf);
				break;*/

		case 9:	 printf("Enter the first string:\n");
                if(NULL == (sbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(sbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }

				 printf("Enter the second string:\n");
                if(NULL == (dbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(dbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }
			
				n = strrot(sbuf, dbuf);
				if( n == 0)
					printf("dbuf is a rotated string of sbuf\n");
				else
					printf("dbuf is not a rotated string of sbuf\n");
				break;
				
		case 11: printf("Enter the string:\n");
				 if(NULL == (sbuf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                 }

                 if(NULL == (fgets(sbuf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }
				
				printf("Enter the character ch:\n");
				if(NULL == (buf = (char *)malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(buf, MAX, stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }
 				
				printf("Enter the position:\n");
				if(NULL == (buf  = (char *) malloc (sizeof(char)* MAX))){
                     perror("malloc failed\n");
                     exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(buf,MAX,stdin))) {
                     perror("fgets failed");
                     exit(EXIT_FAILURE);
                 }
				pos = atoi(buf);

				insertchar( sbuf , ch , pos);
				printf("output = %s\n",sbuf);
				break;


		default : break;
	}
	return 0;
}	

#endif
