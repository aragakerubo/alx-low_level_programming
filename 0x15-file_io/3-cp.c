#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Description: copies the content of a file to another file
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, read_bytes, write_bytes;
	char buffer[BUFFERSIZE];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	/* open file_from */
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
			exit(98);

	/* open file_to */
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	/* read file_from */
	while ((read_bytes = read(file_from, buffer, 1024)) > 0)
	{
		write_bytes = write(file_to, buffer, read_bytes);
		if (write_bytes != read_bytes || write_bytes == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	if (read_bytes == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
			exit(98);

	/* close file_from */
	if (close(file_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

	/* close file_to */
	if (close(file_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

	return (0);
}
