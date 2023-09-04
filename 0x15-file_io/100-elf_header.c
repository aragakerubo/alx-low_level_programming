#include "main.h"

/**
 * magic - displays the magic number
 * @elf_ident: ELF header identifier
 *
 * Description: displays the magic number
 *
 * Return: void
 */
void magic(unsigned char *elf_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", elf_ident[i]);
		if (i != EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * class - displays the class
 * @elf_ident: ELF header identifier
 *
 * Description: displays the class
 *
 * Return: void
 */
void class(unsigned char *elf_ident)
{
	printf("  Class:                             ");

	switch (elf_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 * data - displays the data
 * @elf_ident: ELF header identifier
 *
 * Description: displays the data
 *
 * Return: void
 */
void data(unsigned char *elf_ident)
{
	printf("  Data:                              ");

	switch (elf_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_DATA]);
	}
}

/**
 * version - displays the version
 * @elf_ident: ELF header identifier
 *
 * Description: displays the version
 *
 * Return: void
 */
void version(unsigned char *elf_ident)
{
	printf("  Version:                           %d",
	       elf_ident[EI_VERSION]);

	switch (elf_ident[EI_VERSION])
	{
	case EV_NONE:
		printf(" (invalid)\n");
		break;
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf(" <unknown: %x>\n", elf_ident[EI_VERSION]);
	}
}

/**
 * osabi - displays the OS/ABI
 * @elf_ident: ELF header identifier
 *
 * Description: displays the OS/ABI
 *
 * Return: void
 */
void osabi(unsigned char *elf_ident)
{
	printf("  OS/ABI:                            ");

	switch (elf_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_OSABI]);
	}
}

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

/**
 * main - displays the information contained in the ELF header at
 * the start of an ELF file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Description: displays the information contained in the ELF header at
 * the start of an ELF file
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_desc, read_bytes;
	unsigned char elf_ident[EI_NIDENT];
	Elf64_Ehdr *header;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"),
		    exit(98);
	/* open file */
	file_desc = open(argv[1], O_RDONLY);
	if (file_desc == -1)
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]),
		    exit(98);
	/* read ELF header identifier */
	read_bytes = read(file_desc, elf_ident, EI_NIDENT);
	if (read_bytes == -1)
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]),
		    exit(98);
	/* verify ELF header identifier */
	verify_elf(elf_ident);
	/* allocate memory for header struct */
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
		dprintf(STDERR_FILENO, "Error: memory allocation failed\n"),
		    exit(98);
	/* read ELF header */
	lseek(file_desc, 0, SEEK_SET);
	read_bytes = read(file_desc, header, sizeof(Elf64_Ehdr));
	if (read_bytes == -1)
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]),
		    exit(98);
	/* display ELF header */
	display_header(header, elf_ident);
	free(header);
	/* close file */
	file_desc = close(file_desc);
	if (file_desc == -1)
		dprintf(STDERR_FILENO, "Error: cannot close fd %d\n", file_desc),
		    exit(98);

	return (0);
}

