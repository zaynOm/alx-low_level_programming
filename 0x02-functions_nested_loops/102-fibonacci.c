#include <stdio.h>
/**
 * main - entry point
 *
 * Descreption: this program prints the first 50 Fibonacci numbers
 * starting from 1 and 2.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long x = 1;
	unsigned long y = 1;
	unsigned long sum = 1;
	int i;

	for (i = 0; i < 49; i++)
	{
		printf("%lu, ", sum);
		sum = x + y;
		x = y;
		y = sum;
	}
	printf("%lu\n", sum);

	return (0);
}
