#include <stdio.h>
/**
 * atoi_check - converts a string to integer, and checks
 * if the string contains a non digit character
 * @n: a pointer to a string
 * @sum: a pointer to an int where the convertion is stored
 *
 * Return: -1 if n contains a non digit character, otherwise 0
 */

int atoi_check(char *n, int *sum)
{
	int sign = 1;

	if (*n == '-')
	{
		sign *= -1;
		n++;
	}
	while (*n)
	{
		if (*n < 48 || *n > 58)
			return (-1);

		*sum = (*sum * 10) + *n - 48;
		n++;
	}

	*sum *= sign;
	return (0);
}


/**
 * main - Entry point
 * Desc: adds positive numbers
 * @argc: argumrnts count
 * @argv: pointer to an array of strings
 *
 * Return: 1 if one of the numbers contains a non digit symbol, otherwise 0
 */
int main(int argc, char **argv)
{
	int num;
	int sum = 0;
	int i;

	for (i = 1; i < argc; i++)
	{
		int x;

		num = 0;
		x = atoi_check(argv[i], &num);

		if (x == -1)
		{
			printf("Error\n");
			return (1);
		}
		sum += num;
	}

	printf("%d\n", sum);
	return (0);
}
