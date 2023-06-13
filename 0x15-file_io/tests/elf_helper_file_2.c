#include "main.h"

/**
 * abiversion - displays the ABI version
 * @e_ident: ELF header identifier
 *
 * Description: displays the ABI version
 *
 * Return: void
 */
void abiversion(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * type - displays the type
 * @e_type: ELF header type
 *
 * Description: displays the type
 *
 * Return: void
 */
void type(unsigned int e_type)
{
	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * entry - displays the entry point address
 * @e_entry: ELF header entry point address
 *
 * Description: displays the entry point address
 *
 * Return: void
 */
void entry(unsigned long int e_entry)
{
	printf("  Entry point address:               %lx\n", e_entry);
}

/**
 * display_header - displays the ELF header
 * @header: ELF header
 * @e_ident: ELF header identifier
 *
 * Description: displays the ELF header
 *
 * Return: void
 */
void display_header(Elf64_Ehdr *header, unsigned char *e_ident)
{
	printf("ELF Header:\n");

	/* display magic */
	magic(e_ident);

	/* display class */
	class(e_ident);

	/* display data */
	data(e_ident);

	/* display version */
	version(e_ident);

	/* display OS/ABI */
	osabi(e_ident);

	/* display ABI version */
	abiversion(e_ident);

	/* display type */
	type(header->e_type);

	/* display entry point address */
	entry(header->e_entry);
}
