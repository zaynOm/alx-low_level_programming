#include "main.h"

/**
 * _puts - prints a string followed by a new line
 * @str: a pointer that points to a string
 */
void _puts(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		_putchar(*(str + i));
		i++;
	}
	_putchar('\n');
}
