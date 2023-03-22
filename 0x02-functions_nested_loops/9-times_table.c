#include "main.h"
/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i, j, result;

	for (i = 0; i < 10; i++)
	{
		_putchar(48);
		for (j = 1; j < 10; j++)
		{
			result = i * j;

			if (j == 9 && i < 2)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar(result + 48);
				_putchar('$');
			}
			else if (j == 9)
			{
				_putchar(' ');
				_putchar(result / 10 + 48);
				_putchar(result % 10 + 48);
				_putchar('$');
			}
			else if (result >= 10)
			{
				_putchar(' ');
				_putchar(result / 10 + 48);
				_putchar(result % 10 + 48);
				_putchar(',');
			}
			else
			{
				_putchar(' ');
				_putchar(' ');
				_putchar(result + 48);
				_putchar(',');
			}
		}
		_putchar('\n');
	}
}
