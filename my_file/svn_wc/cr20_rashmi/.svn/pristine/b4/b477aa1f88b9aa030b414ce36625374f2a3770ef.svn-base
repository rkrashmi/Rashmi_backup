//check for invalid inputs//

#include"header.h"

void my_fgets(unsigned int *num)
{
	char *buf = NULL;

	if(NULL == (buf  = (char *) malloc (sizeof(char)* MAX))){
                    perror("malloc failed\n");
                    exit(EXIT_FAILURE);
                }

                if(NULL == (fgets(buf,MAX,stdin))) {
                    perror("fgets failed");
                    exit(EXIT_FAILURE);
                }

}
