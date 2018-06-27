#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

int main(int argc, char* argv[])
{

    FILE *fp;

	int i ;
    Elf32_Ehdr var1 ;
	Elf32_Shdr var2[30] ;
    int sample ;
    int value ;

	Elf32_Phdr var[9] ;
	char str[50];
	char str1[50];
	char flg[10] ;



	fp = fopen(argv[1], "r");

    sample = fread ( &var1, sizeof ( var1 ), 1, fp ) ;
    if ( 0 == sample ) {
        printf ("fread failed\n") ;
        return -1 ;
    }

//    printf ("ELF Header:\n") ;

    //Magic 
	if(var1.e_ident[0] != 0x7f) {
		printf("readelf: Error: Not an ELF file - it has the wrong magic bytes at the start\n");
		return 0;
	}

	printf ("ELF Header:\n") ;

    printf ("  Magic:  ") ;

    for ( i = 0 ; i < EI_NIDENT ; i++ ) {
        printf ("%.2x ", var1.e_ident[i] ) ;
    }
    printf ("\n") ;

//Class

    printf ("  Class:                               ") ;
    value = var1.e_ident[EI_CLASS] ;

    if ( 0 == value ) {
        printf ("ELFCLASSNONE \n") ;
    } 
	else if ( 1 == value ) {
        printf ("ELF32 \n") ;
    } 
	else if ( 2 == value ) {
        printf ("ELF64 \n") ;
    } 
	else {
        printf ("ELFCLASS%d \n",value ) ;
    }

//Data

    printf ("  Data:                                ") ;
    value = var1.e_ident[EI_DATA] ;
    if ( 0 == value ) {
        printf (" Invalid data encoding \n") ;
    }
	else if ( 1 == value ) {
        printf ("2's compliment, little endian \n") ;
    } 
	else if ( 2 == value ) {
        printf ("2's compliment, big  endian \n") ;
    } 
	else {
        printf ("ELFDATA%d \n",value ) ;
    }

//Version

    printf ("  Version:\t\t\t  ") ;
    printf ("     %d (current)\n", var1.e_ident[EI_VERSION] ) ;

//OS/ABI

    printf ("  OS/ABI:\t\t\t       ") ;
    value = var1.e_ident[EI_OSABI] ;
    if ( 0 == value ) {
        printf ("UNIX - System V \n") ;
    }

//ABI Version

    printf ("  ABI Version:\t\t\t       ") ;
    printf ("%d\n", var1.e_ident[EI_ABIVERSION]) ;

//Type

    printf ("  Type:\t\t\t\t ") ;
    value = var1.e_type ;

    if ( 0 == value ) {
        printf ("      NONE (No filetype)\n") ;
    }
	else if ( 1 == value ) {
        printf ("      REL (Relocatable file) \n") ;
    }
	else if ( 2 == value ) {
        printf ("      EXEC (Executable file) \n") ;
    }
	else if ( 3 == value ) {
        printf ("      DYN (Shared object file) \n") ;
    }
	else if ( 4 == value ) {
        printf ("     CORE (Core file) \n") ;
    }

//Machine

    printf ("  Machine:\t\t\t ") ;
    value = var1.e_machine ;
    if ( 0 == value ) {
        printf ("      No Machine  \n") ;
    } 
	else if ( 3 == value ) {
        printf ("      Intel 80386 \n") ;
    }
	else if ( 2 == value ) {
        printf ("      EXEC (Executable file) \n") ;
    }

//Version

    printf ("  Version:\t\t\t       ") ; 
    printf ("0x%x\n", var1.e_version ) ;

//Entry point address

    printf ("  Entry point address:\t\t       ") ;
    printf ("0x%x\n", var1.e_entry ) ;

//Start of program headers

    printf ("  Start of program headers:\t       ") ;
    printf ("%d (bytes into file) \n", var1.e_phoff ) ;

//Start of section headers

    printf ("  Start of section headers:\t       ") ;
    printf ("%d (bytes into file) \n", var1.e_shoff ) ;

//Flags

    printf ("  Flags:\t\t\t       ") ;
    printf ("0x%x\n", var1.e_flags ) ;

//Size of this header

    printf ("  Size of this header:\t\t       ") ;
    printf ("%d (bytes) \n", var1.e_ehsize ) ;

//Size of program headers

    printf ("  Size of program headers:\t      ");
    printf (" %d (bytes)\n", var1.e_phentsize) ;

//Numbers of program headers

    printf ("  Number of program headers:\t       ") ;
    printf ("%d \n", var1.e_phnum ) ;

//Size of section headers

    printf ("  Size of section headers:\t       ") ;
    printf ("%d (bytes) \n", var1.e_shentsize ) ;

//Number of section headers

    printf ("  Number of section headers:\t       ") ;
    printf ("%d \n", var1.e_shnum ) ;

//Section header string table index

    printf ("  Section header string table index:   ") ;
    printf ("%d\n", var1.e_shstrndx ) ;
    printf ("\n") ;
//    rewind ( fp ) ;


//--------------------------SECTION HEADER-----------------------------------------------

//	Elf32_Shdr var2[30] ;
//    char str[50];
//    char str1[50];
//    char flg[10] ;

    fread ( &var2, sizeof ( var2 ), 1, fp ) ;
//    rewind ( fp ) ;

    fseek ( fp, var1.e_shoff, SEEK_SET ) ;
	//	for(i =0 ;i <30;i++){
		printf("%s\n", var2[1].sh_name);
	//	}
  /*  printf ("Section Headers:\n") ;
    printf ("  %-4s %-20s %-10s %-8s %-6s %-5s  %-2s %-s %-s %-s %-s\n", "[Nr]", "Name", "Type", "Addr", "Off", "Size", "ES", "Flg", "Lk", "Inf", "Al" ) ;


    for ( i = 0 ; i < var1.e_shnum ; i++ ) {

        fseek ( fp, var2[var1.e_shnum - 3].sh_offset + var2[i].sh_name, SEEK_SET ) ;
        fread ( str, 50, 1, fp); 
        value = var2[i].sh_type ;*/

//-----------------------PROGRAM HEADER----------------------------------------------------------
	if(var1.e_type != 2) {
        printf("There are no program headers in this file.\n");
//        return 0;
    }

	else {
	printf("Program Headers:\n") ;


    printf ("  Type            Offset   VirtuAddr   PhysAddr   Filesiz   Memsiz  Flg Align\n") ;
//    fseek ( fp, 52, SEEK_SET ) ;
    for ( i = 0 ; i < var1.e_phnum ; i++ ) {
        value = fread ( &var[i], sizeof ( var[i] ), 1, fp ) ;
        if ( 0 == value ) {
            printf ("fread failed\n") ;
            return -1 ;
        }

        value = var[i].p_type ;
        switch ( value ) {
            case 0:
                printf ("  %-16s", "NULL") ;
                break ;
            case 1:
                printf ("  %-16s", "LOAD") ;
                break ;
            case 2:
                printf ("  %-16s", "DYNAMIC") ;
                break ;
            case 3:
                printf ("  %-16s", "INTERP") ; 
                break ;
            case 4:
                printf ("  %-16s", "NOTE") ;
                break ;
            case 6:
                printf ("  %-16s", "PHDR") ;
                break ;
            case 0x6474e550:
                printf ("  %-16s", "GNU_EH_FRAME") ;
                break ;
            case 0x6474e551:
                printf ("  %-16s", "GNU_STACK") ; 
                break ;
            case 0x6474e552:
                printf ("  %-16s", "GNU_RELRO") ;
                break ;

        }
        
        printf (" 0x%.6x", var[i].p_offset ) ;

        printf (" 0x%.8x", var[i].p_vaddr ) ;
        printf ("  0x%.8x", var[i].p_paddr) ;
        printf (" 0x%.5x", var[i].p_filesz) ;
        printf ("   0x%.5x", var[i].p_memsz ) ;

        value = var[i].p_flags ;
        
        switch ( value ) {
            case 1:
                printf ("%3s", " E  ") ;
                break ;
            case 2:   
                printf ("%3s", " W  ") ;
                break ;
            case 4:
                printf ("%3s", " R  ") ;    
                break ;
            case 5:
                printf ("%3s", " R E") ;    
                break ;
            case 6:
                printf ("%3s", " RW ") ;    
                break ;
        }
        printf (" 0x%x\n", var[i].p_align ) ;
        if ( 1 == i ) {
            printf ("      [Requesting program interpreter: /lib/ld-linux.so.2]\n") ;
        }
        
    }
    printf ("\n") ;

	}

    return 0 ;
}





