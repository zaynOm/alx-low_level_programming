#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: unsigned long integer
 */
void print_binary(unsigned long int n)
{
	unsigned long x = 1;

	if (!n)
	{
		_putchar('0');
		return;
	}
	while (x <= n)
		x <<= 1;

	if (x > n)
		x >>= 1;

	while (x)
	{
		_putchar((n & x) ? '1' : '0');
		x >>= 1;
	}
}
