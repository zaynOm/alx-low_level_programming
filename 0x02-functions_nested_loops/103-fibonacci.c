#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned int x = 0, y = 1, z = 0;
	unsigned int sum;

	while (z < 4000000)
	{
		z = x + y;
		x = y;
		y = z;
		if (z % 2 == 0)
			sum += z;
	}
	printf("%d\n", sum);

	return (0);
}
