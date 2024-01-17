#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array using Jump Search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where the value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump_size = sqrt(size);
	size_t prev = 0;
	size_t i;

	if (!array)
		return (-1);

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

		prev += jump_size;

		if (prev >= size)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev - jump_size, prev);

	for (i = prev - jump_size; i <= fmin(prev, size - 1); i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
