#include <stdio.h>
/**
 * print_to_98 - prints all natural numbers from @n to 98
 * @n: the integer to start from
 */
void print_to_98(int n)
{
	printf("%d", n);

	while (n != 98)
	{
		if (n < 98)
			n++;
		else
			n--;
		printf(", %d", n);
	}
	putchar('\n');
}
