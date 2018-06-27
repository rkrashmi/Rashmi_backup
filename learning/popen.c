// Program to experiment popen()
#include <stdio.h>

int main() {

	if(-1 == readEndForThisProcess()) {
		printf("Error\n");
	}

	if(-1 == writeEndForThisProcess()) {
		printf("Error\n");
	}

	return 0;
}

int readEndForThisProcess() {
	FILE *fp;
	char path[50];

	fp = popen("ls", "r");
	if (fp == NULL) {
		printf("Error while opening\n");
		return -1;
	} else {
		/** Reading the data from file pointer which is read end for this process
			* and write end for the process created by popen() */
		printf("Reading data from pipe\n\n");
		while (fgets(path, 50, fp) != NULL) {
			printf("%s", path);
		}

		// Closing the file opened by popen()
		if (-1 == pclose(fp)) {
			printf("Error while closing\n");
			return -1;
		} else {
			printf("Successfully closed\n");
		}
	}

}

int writeEndForThisProcess() {
	FILE *fp;

	fp = popen("sh", "w");
	if (fp == NULL) {
		printf("Error while opening\n");
		return -1;
	} else {
		/** Writing the data to file pointer which is write end for this process
			* and read end for the process created by popen() */
		printf("\nWriting data to pipe\n\n");
		if(0 > fputs("ls", fp)) {
			printf("Error\n");
			return -1;
		} else {
			printf("Success\n");
		}

		// Closing the file opened by popen()
		if (-1 == pclose(fp)) {
			printf("Error while closing\n");
			return -1;
		} else {
			printf("Successfully closed\n");
		}
	}

	return 1;
}
