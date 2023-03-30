#include "main.h"
/**
 * print_number - prints an integer
 *
 * @n: number to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		if (n == -2147483648)
		{
			_putchar('2');
			print_number(147483648);
			return;
		}
		n *= -1;
	}

	if (n >= 10)
		print_number(n / 10);

	_putchar((n % 10) + 48);

}
