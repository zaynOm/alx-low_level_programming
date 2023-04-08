#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Desc: prints the minimum number of coins to make
 * change for an amount of money.
 * @argc: number of arguments
 * @argv: pointer to an array of arguments
 *
 * Return: number of coins, (1) if number of passed argumrnts is not exactly 1
 */

int main(int argc, char **argv)
{
	int num;
	int cn = 0;

	(void) argc;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	num =  atoi(argv[1]);

	if (num / 25 >= 1)
	{
		cn += num / 25;
		num = num - (num / 25) * 25;
	}
	if (num / 10 >= 1)
	{
		cn += num / 10;
		num = num - (num / 10) * 10;
	}
	if (num / 5 >= 1)
	{
		cn += num / 5;
		num = num - (num / 5) * 5;
	}
	if (num / 2 >= 1)
	{
		cn += num / 2;
		num = num - (num / 2) * 2;
	}
	if (num == 1)
		cn++;

	printf("%d\n", cn);
	return (0);

}
