#include <stdio.h>

/**
 * main - prints the name of it's excutable followed by a new line.
 * @argc: the number of arguments
 * @argv: a pointer to an array of arguments
 *
 * Return: Always 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	printf("%s\n", argv[0]);

	return (0);
}
