#include <stdio.h>
/**
 * atoi - converts a string into int
 * @n: the string to convert
 *
 * Return: a number
 */
int atoi(char *n)
{
	int sum = 0;
	int sign = 1;

	if (*n == '-')
	{
		sign *= -1;
		n++;
	}
	while (*n)
	{
		sum = (sum * 10) + *n - 48;
		n++;
	}

	return (sum * sign);
}


/**
 * main - Entry point
 * Desc: multiplies two numbers given as arguments
 * @argc: arguments count
 * @argv: pointer to an array of strings
 *
 * Return: the multiplication result, (1) if the args are less then 2
 *
 */
int main(int argc, char **argv)
{
	int r;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	r = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", r);

	return (0);
}
