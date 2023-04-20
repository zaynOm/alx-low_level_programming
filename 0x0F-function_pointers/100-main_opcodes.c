#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the opcodes of its own
 * @ac: arguments number
 * @av: array of arguments
 *
 * Return: (0) on seccess, (1) if ac is not 2,
 * (2) if given number of bytes is negative.
 */
int main(int ac, char *av[])
{
	int i, nbts;
	char *func_ptr;

	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}
	nbts = atoi(av[1]);
	if (nbts < 0)
	{
		printf("Error\n");
		exit(2);
	}
	func_ptr = (char *)main;
	for (i = 0; i < nbts - 1; i++)
		printf("%2hhx ", func_ptr[i]);

	printf("%2hhx\n", func_ptr[i]);
	return (0);
}
