#include "main.h"
/**
 * print_sign - prints '+' if n is bigger then 0
 * '-' if n is less then 0
 * '0' if n is equal to 0
 * @n: decimal to compare and print
 *
 * Return: (1) if n is greater then zero
 * (0) if n is zero
 * (-1) if n is less then zero.
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
