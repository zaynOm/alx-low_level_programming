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
	int coins[5] = {25, 10, 5, 2, 1};
	int i;

	(void) argc;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num =  atoi(argv[1]);

	for (i = 0; i < 5; i++)
	{
		int d = num / coins[i];

		if (d >= 1)
		{
			cn += d;
			num = num - d * coins[i];
		}
	}

	printf("%d\n", cn);
	return (0);

}
