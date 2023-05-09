#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: pointer to a string containing the file name
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure or @filename is null
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes, len = 0;

	if (!filename)
		return (-1);

	if (text_content)
	{
		while (text_content[len++])
			;
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	bytes = write(fd, text_content, len);

	if (fd == -1 || bytes == -1)
		return (-1);

	close(fd);
	return (1);
}
