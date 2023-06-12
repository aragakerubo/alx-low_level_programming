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
