#include "main.h"
/**
 * print_number - prints an integer
 * @n: the integer to print
 *
 */
void print_number(int n)
{
	int i, len;

	if (b < 0)
	{
		len = number_len(b * -1);
		b = b * -1;
		_putchar('-');
	}
	else
		len = number_len(b);
	if (b == 0)
		_putchar('0');
	for (i = len; i > 0; i /= 10)
	{
		_putchar(b / i + 48);
		b = b - (b / i) * i;
	}
}
