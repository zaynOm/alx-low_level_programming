#include <stdio.h>
/**
 * main - Entry point
 *
 * Desc: this program prints the first 98 Fibonacci numbers
 * starting from 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned int x = 0;
	unsigned int y = 1;
	unsigned int z;
	int i;

	for (i = 0; i < 97; i++)
	{
		z = x + y;
		x = y;
		y = z;
		printf("%u, ", z);
	}
	printf("%u\n", z);
	return (0);
}
