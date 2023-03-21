#include "main.h"
/**
 * main - Entry point
 *
 * Description: it outputs '_putchar'
 *
 * Return: Always (0)
 */
int main(void)
{
	char word[8] = "_putchar";
	int i = 0;

	while (i < (int)sizeof(word))
	{
		_putchar(word[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}
