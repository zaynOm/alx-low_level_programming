#include <stdio.h>
/**
 * print_array - prints elements of an array of integers
 * @a: the array of integers
 * @n: number of elements of the array
 */
void print_array(int *a, int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n - 1; i++)
			printf("%d, ", a[i]);

		printf("%d\n", a[n - 1]);
	} else
		printf("\n");
}
