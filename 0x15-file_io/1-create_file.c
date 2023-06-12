#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Description: creates a file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_desc, i, write_bytes;

	if (filename == NULL)
		return (-1);

	/* open file */
	file_desc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_desc == -1)
		return (-1);

	/* write file */
	if (text_content != NULL)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;
		write_bytes = write(file_desc, text_content, i);
		if (write_bytes == -1)
			return (-1);
	}

	close(file_desc);

	return (1);
}
