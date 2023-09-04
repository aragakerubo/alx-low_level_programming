#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file to read
 * @letters: number of letters to read and print
 *
 * Description: reads a text file and prints it to the POSIX standard output
 *
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_desc;
	ssize_t read_bytes, write_bytes;
	char *buffer;

	if (filename == NULL)
		return (0);

	/* open file */
	file_desc = open(filename, O_RDONLY);
	if (file_desc == -1)
		return (0);

	/* allocate memory for buffer */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	/* read file */
	read_bytes = read(file_desc, buffer, letters);
	if (read_bytes == -1)
	{
		free(buffer);
		return (0);
	}

	/* write file */
	write_bytes = write(STDOUT_FILENO, buffer, read_bytes);
	if (write_bytes == -1)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(file_desc);

	return (write_bytes);
}
