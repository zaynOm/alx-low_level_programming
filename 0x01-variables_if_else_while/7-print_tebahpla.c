#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	char c = 122;

	while (c >= 97)
	{
		putchar(c);
		c--;
	}
	putchar(10);

	return (0);
}
