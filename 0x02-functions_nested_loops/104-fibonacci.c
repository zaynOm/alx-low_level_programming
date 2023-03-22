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
	unsigned long int x = 0;
	unsigned long int y = 1;
	unsigned long int z;
	int i;

	for (i = 0; i < 97; i++)
	{
		z = x + y;
		x = y;
		y = z;
		printf("%lu, ", z);
	}
	printf("%lu\n", z);
	return (0);
}
