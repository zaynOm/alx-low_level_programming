#include "main.h"
/**
 * err - pritns error msg & exit with the corresponding error code
 * @file: file name causing the error
 * @err: error number
*/
void err(char *file, int err)
{
	if (err == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	if (err == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", err);
		exit(100);
	}
}

/**
 * close_fd - close a file descriptor,
 * if it can close it exit with code 100 and print an error msg
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
		err("", fd);
}
/**
 * main - copies the content of a file to another file.
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success,
 * or the corresponding error code (97, 98, 99, or 100) on failure.
 *
 */
int main(int ac, char *av[])
{
	int file_from, file_to, re, wr;
	char buff[1024];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (ac != 3)
	{
		dprintf(STDOUT_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = open(av[1], O_RDONLY);
	if (file_from == -1)
		err(av[1], 98);
	file_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (file_to == -1)
		err(av[2], 99);
	do {
		re = read(file_from, buff, 1024);
		if (re == -1)
			err(av[1], 98);
		wr = write(file_to, buff, re);
		if (wr == -1 || wr != re)
			err(av[2], 99);
	} while (re == 1024);
	close_fd(file_from);
	close_fd(file_to);

	return (0);
}
