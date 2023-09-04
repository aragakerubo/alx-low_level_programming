#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Description: appends text at the end of a file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_desc, i, write_bytes;

	if (filename == NULL)
		return (-1);

	/* open file */
	file_desc = open(filename, O_WRONLY | O_APPEND);
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
