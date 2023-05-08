#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer to a string containing the file name
 * @letters: the number of letters it should read and print
 *
 * Return: the number of letters it could read and print, 0 if an error occurs
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fop, fre, fwr;

	buff = malloc(sizeof(char) * letters);
	if (!filename || !buff)
		return (0);

	fop = open(filename, O_RDONLY);
	fre = read(fop, buff, letters);
	fwr = write(1, buff, fre);

	if (fop * fre * fwr < 0 || fre != fwr)
	{
		free(buff);
		return (0);
	}
	free(buff);
	close(fop);
	return (fwr);
}
