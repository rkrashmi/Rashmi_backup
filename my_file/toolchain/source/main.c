#include "header.h"

int main(int argc, char* argv[])
{

    FILE *fp;
	int index;
	size_t header_p;
	Elf32_hdr *ptr = NULL;
	int read_value;
	

    fp = fopen(argv[1], "r");
	ptr = (Elf32_hdr*)malloc(sizeof(Elf32_hdr*));

	header_p = fread( ptr, sizeof( ptr ), 1, fp);
		
	printf("ELF Header:\n");

//for magic numbers
	printf("  Magic:   ");

	for( index = 0 ; index < EI_NIDENT; index++){
		printf(" %.2x"   

//for class
	printf("  Class:\t\t\t\t");
	switch( (c = fgetc(fp)) ){

		case ETT_NONE: printf("No file\n");
					   break;
		case ETT_EELF: printf("Relocatable file\n");
					   break;
		case ETT_EXE: printf("ELF32\n");
					   break;
		case ETT_DYNC: printf("Dynamically Shared file\n");
					   break;
		case ETT_CORE: printf("Core file\n");
					   break;
		case ETT_LPRC: printf("Low Processor specific\n");
					   break;
		case ETT_HPRC: printf("High Processor specific\n");
					   break;
		      default: break;
	}
		printf(

	return 0;
}
