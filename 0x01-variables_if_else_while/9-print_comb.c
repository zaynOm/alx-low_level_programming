#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	int n = '0';

	while (n <= '9')
	{
		putchar(n);
		if (n == '9')
			break;
		putchar(',');
		putchar(' ');
		n++;
	}
	putchar('\n');

	return (0);
}