#include "main.h"
/**
 * print_most_numbers - prints numbers from 0 to 9, but not 2 and 4
 * followed by a new line
 */
void print_most_numbers(void)
{
	int i = 0;

	while (i < 10)
	{
		if (!(i == 2 || i == 4))
			_putchar(i + 48);
		i++;
	}
	_putchar('\n');
}
