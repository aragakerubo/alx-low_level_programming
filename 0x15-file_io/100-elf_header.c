#include "main.h"

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
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	}
	file_desc = open(argv[1], O_RDONLY);
	if (file_desc == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]);
		exit(98);
	}
	read_bytes = read(file_desc, elf_ident, EI_NIDENT);
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]);
		exit(98);
	}
	verify_elf(elf_ident);
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
		dprintf(STDERR_FILENO, "Error: memory allocation failed\n"), exit(98);
	lseek(file_desc, 0, SEEK_SET);
	read_bytes = read(file_desc, header, sizeof(Elf64_Ehdr));
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot read file %s\n", argv[1]);
		exit(98);
	}
	display_header(header, elf_ident);
	free(header);
	file_desc = close(file_desc);
	if (file_desc == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot close fd %d\n", file_desc);
		exit(98);
	}
	return (0);
}

