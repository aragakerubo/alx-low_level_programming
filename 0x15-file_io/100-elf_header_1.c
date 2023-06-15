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
