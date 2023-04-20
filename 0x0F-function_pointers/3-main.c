#include "3-calc.h"
/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of strings
 *
 * Return: 98 if ac is not 4, 99 for unvalide operator, otherwise 0.
 */
int main(int ac, char *av[])
{
	int (*op_fun)(int, int);

	if (ac != 4)
	{
		printf("Error\n");
		exit(98);
	}


	op_fun = get_op_func(av[2]);
	if (!op_fun)
	{
		printf("Error\n");
		exit(99);
	}

	if ((av[2] == '/' || av[2] == '%') && av[3] == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", op_fun(atoi(av[1]), atoi(av[3])));
	return (0);
}
