#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	int c1;
	int c2 = '1';
	int x = '1';

	for (c1 = '0'; c1 < '9'; c1++)
	{
		while (c2 <= '9')
		{
			putchar(c1);
			putchar(c2);
			if (c1 == '8' && c2 == '9')
				break;
			putchar(',');
			putchar(' ');
			c2++;
		}
		x += 1;
		c2 = x;
	}
	putchar('\n');

	return (0);
}
