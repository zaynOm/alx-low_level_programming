#include "search_algos.h"

/**
 * binary_search - using Binary search algorithm to look for a value.
 * @array: pointer to the first element of the array to search in.
 * @size: size of the @array.
 * @value: the value to search for.
 *
 * Return: the index of the value if found, otherwise -1.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l, r, m, i;

	l = 0;
	r = size - 1;

	if (!array)
		return (-1);

	while (l <= r)
	{
		printf("Searching in array: %d", array[l]);
		for (i = l + 1; i <= r; i++)
			printf(", %d", array[i]);
		printf("\n");

		m = (l + r) / 2;
		if (array[m] < value)
			l = m + 1;
		else if (array[m] > value)
			r = m - 1;
		else
			return (m);
	}

	return (-1);
}
