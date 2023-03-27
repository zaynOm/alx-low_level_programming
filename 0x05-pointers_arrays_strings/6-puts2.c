#include "main.h"
/**
 * puts2 - prints every other character of a string
 * starting from the first one
 * @str: the string to put
 */
void puts2(char *str)
{
	int i = 0;
	int j = 0;

	while (str[i])
		i++;

	while (j < i)
	{
		_putchar(str[j]);
		j += 2;
	}
	_putchar('\n');
}
