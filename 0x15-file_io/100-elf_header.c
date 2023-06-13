#include "main.h"

/**
 * magic - displays the magic number
 * @e_ident: ELF header identifier
 *
 * Description: displays the magic number
 *
 * Return: void
 */
void magic(unsigned char *e_ident)
{
        int i;

        printf("  Magic:   ");

        for (i = 0; i < EI_NIDENT; i++)
                printf("%02x ", e_ident[i]);
        printf("\n");
}

/**
 * class - displays the class
 * @e_ident: ELF header identifier
 *
 * Description: displays the class
 *
 * Return: void
 */
void class(unsigned char *e_ident)
{
        printf("  Class:                             ");

        switch (e_ident[EI_CLASS])
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
                printf("<unknown: %x>\n", e_ident[EI_CLASS]);
        }
}

/**
 * data - displays the data
 * @e_ident: ELF header identifier
 *
 * Description: displays the data
 *
 * Return: void
 */
void data(unsigned char *e_ident)
{
        printf("  Data:                              ");

        switch (e_ident[EI_DATA])
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
                printf("<unknown: %x>\n", e_ident[EI_DATA]);
        }
}

/**
 * version - displays the version
 * @e_ident: ELF header identifier
 *
 * Description: displays the version
 *
 * Return: void
 */
void version(unsigned char *e_ident)
{
        printf("  Version:                           %d",
               e_ident[EI_VERSION]);

        switch (e_ident[EI_VERSION])
        {
        case EV_NONE:
                printf(" (invalid)\n");
                break;
        case EV_CURRENT:
                printf(" (current)\n");
                break;
        default:
                printf(" <unknown: %x>\n", e_ident[EI_VERSION]);
        }
}

/**
 * osabi - displays the OS/ABI
 * @e_ident: ELF header identifier
 *
 * Description: displays the OS/ABI
 *
 * Return: void
 */
void osabi(unsigned char *e_ident)
{
        printf("  OS/ABI:                            ");

        switch (e_ident[EI_OSABI])
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
                printf("<unknown: %x>\n", e_ident[EI_OSABI]);
        }
}

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
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	}
	file_desc = open(argv[1], O_RDONLY);
	if (file_desc == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]), exit(98);
	}
	read_bytes = read(file_desc, e_ident, EI_NIDENT);
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]), exit(98);
	}
	if (e_ident[EI_MAG0] != 0x7f || e_ident[EI_MAG1] != 'E' ||
	    e_ident[EI_MAG2] != 'L' || e_ident[EI_MAG3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: file is not ELF\n"), exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		dprintf(STDERR_FILENO, "Error: memory allocation failed\n"), exit(98);
	}
	lseek(file_desc, 0, SEEK_SET);
	read_bytes = read(file_desc, header, sizeof(Elf64_Ehdr));
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]);
		exit(98);
	}
	display_header(header, e_ident);
	free(header);
	close(file_desc);

	return (0);
}
