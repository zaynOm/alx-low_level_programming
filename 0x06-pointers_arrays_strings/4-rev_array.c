#include <stdio.h>
/**
 * reverse_array - reverses the content of an array of integers
 *
 * @a: array of integers
 * @n: size of the array
 */
void reverse_array(int *a, int n)
{
	int i = 0, j = n - 1;
	int x;

	for (; i < n / 2; i++, j--)
	{
		x = a[i];
		a[i] = a[j];
		a[j] = x;
	}

}
