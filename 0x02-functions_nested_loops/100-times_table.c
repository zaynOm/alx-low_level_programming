#include "main.h"
/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the integer to
 */
void print_times_table(int n)
{
	int i;
	int j;
	int res;

	if (n > 0 && n < 15)
	{
		for (i = 0; i <= n; i++)
		{
			_putchar(48);

			for (j = 1; j <= n; j++)
			{
				_putchar(',');
				_putchar(' ');

				res = i * j;

				if (res < 10)
				{
					_putchar(' ');
					_putchar(' ');
				}
				else if (res > 99)
				{
					_putchar(res / 100 + 48);
					_putchar((res / 10) % 10 + 48);
				}
				else
				{
					_putchar(' ');
					_putchar(res / 10 + 48);
				}
				_putchar(res % 10 + 48);
			}
			_putchar('\n');
		}
	}
}
