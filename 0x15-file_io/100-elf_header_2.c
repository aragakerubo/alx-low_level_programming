#include "main.h"

/**
 * abiversion - displays the ABI version
 * @elf_ident: ELF header identifier
 *
 * Description: displays the ABI version
 *
 * Return: void
 */
void abiversion(unsigned char *elf_ident)
{
	printf("  ABI Version:                       %d\n",
	       elf_ident[EI_ABIVERSION]);
}

/**
 * type - displays the type
 * @e_type: ELF header type
 * @elf_ident: ELF header identifier
 *
 * Description: displays the type
 *
 * Return: void
 */
void type(unsigned int e_type, unsigned char *elf_ident)
{
	printf("  Type:                              ");

	if (elf_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

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
 * @elf_ident: ELF header identifier
 *
 * Description: displays the entry point address
 *
 * Return: void
 */
void entry(unsigned long int e_entry, unsigned char *elf_ident)
{
	printf("  Entry point address:               ");

	if (elf_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry >> 24) & 0xff) |
			  ((e_entry << 8) & 0xff0000) |
			  ((e_entry >> 8) & 0xff00) |
			  ((e_entry << 24) & 0xff000000);
	}

	if (elf_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * verify_elf - verifies if the file is an ELF
 * @elf_ident: ELF header identifier
 *
 * Description: verifies if the file is an ELF
 *
 * Return: void
 */
void verify_elf(unsigned char *elf_ident)
{
	if (elf_ident[EI_MAG0] != 0x7f ||
	    elf_ident[EI_MAG1] != 'E' ||
	    elf_ident[EI_MAG2] != 'L' ||
	    elf_ident[EI_MAG3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * display_header - displays the ELF header
 * @header: ELF header
 * @elf_ident: ELF header identifier
 *
 * Description: displays the ELF header
 *
 * Return: void
 */
void display_header(Elf64_Ehdr *header, unsigned char *elf_ident)
{
	printf("ELF Header:\n");

	/* display magic */
	magic(elf_ident);

	/* display class */
	class(elf_ident);

	/* display data */
	data(elf_ident);

	/* display version */
	version(elf_ident);

	/* display OS/ABI */
	osabi(elf_ident);

	/* display ABI version */
	abiversion(elf_ident);

	/* display type */
	type(header->e_type, elf_ident);

	/* display entry point address */
	entry(header->e_entry, elf_ident);
}
