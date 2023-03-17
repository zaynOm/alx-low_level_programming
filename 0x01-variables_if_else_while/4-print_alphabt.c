#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	char c = 97;

	while (c <= 122)
	{
		if (c == 'q' || c == 'e')
			c++;

		putchar(c);
		c++;
	}
	putchar(10);

	return (0);
}
