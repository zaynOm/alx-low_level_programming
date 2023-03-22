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
	long double x = 0;
	long double y = 0.5;
	long double z;
	int i;

	for (i = 0; i < 98; i++)
	{
		z = x + y;
		x = y;
		y = z;
		if (i == 97)
			printf("%.Lf\n", z * 2);
		else
			printf("%.Lf, ", z * 2);
	}
	return (0);
}
