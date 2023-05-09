#include "main.h"
/**
 * create_file -  creates a file.
 * @filename: pointer to a string containing the file name
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure or @filename is null
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0;
	ssize_t bytes;

	if (!filename)
		return (-1);

	while (text_content[len])
		len++;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	bytes = write(fd, text_content, len);
	if (fd * bytes < 0)
		return (-1);

	close(fd);
	return (1);


}
