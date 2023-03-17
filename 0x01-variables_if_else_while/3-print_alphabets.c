#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	int c = 97;
	int lc = c + 25;

	while (c <= lc)
	{
		putchar(c);
		c++;
		if (c == 123)
		{
			c = 65;
			lc = c + 25;
		}
	}
	putchar(10);

	return (0);
}

