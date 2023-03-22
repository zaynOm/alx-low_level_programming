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
			_putchar(',');
			_putchar(' ');

			result = i * j;

			if (result >= 10)
				_putchar(result / 10 + 48);
			else
				_putchar(' ');

			_putchar(result % 10 + 48);
		}
		_putchar('\n');
	}
}
