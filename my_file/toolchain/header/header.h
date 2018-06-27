#include<stdio.h>
#include<stdlib.h>
//#include<elf.h>

#define EI_INIDENT 16

//macro for e_ident
#define EIMAGIC_0 0x7f

//macro for e_type
#define ETT_NONE  0 	//no file type
#define ETT_EELF  1 	// Relocatable file
#define ETT_EXE   2 	//Executable file
#define ETT_DYNC  3 	//Shared object file
#define ETT_CORE  4 	//Core file
#define ETT_LPRC  0Xff00//Processor specific
#define ETT_HPRC  0xffff//Processor specific


typedef uint32_t	Elf32_Adr;
typedef uint16_t	Elf32_Hlf;
typedef uint32_t	Elf32_Offs;
typedef uint32_t	Elf32_Wrd;

typedef struct {
	unsigned char	e_ident[EI_NIDENT];	/* File identification. */
	Elf32_Hlf	e_type;		/* File type. */
	Elf32_Hlf	e_machine;	/* Machine architecture. */
	Elf32_Wrd	e_version;	/* ELF format version. */
	Elf32_Adr	e_entry;	/* Entry point. */
	Elf32_Offs	e_phoff;	/* Program header file offset. */
	Elf32_Offs	e_shoff;	/* Section header file offset. */
	Elf32_Wrd	e_flags;	/* Architecture-specific flags. */
	Elf32_Hlf	e_ehsize;	/* Size of ELF header in bytes. */
	Elf32_Hlf	e_phentsize;	/* Size of program header entry. */
	Elf32_Hlf	e_phnum;	/* Number of program header entries. */
	Elf32_Hlf	e_shentsize;	/* Size of section header entry. */
	Elf32_Hlf	e_shnum;	/* Number of section header entries. */
	Elf32_Hlf	e_shstrndx;	/* Section name strings section. */
} Elf32_hdr;
