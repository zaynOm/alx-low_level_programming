#include "search_algos.h"

/**
 * linear_search - using Linear search algorithm to look for a value
 * @array: pointer to the first element of the array to search in.
 * @size: size of the @array.
 * @value: the value to search for.
 *
 * Return: the index of the value if found, otherwise -1.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array)
		return (-1);

	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}

	return (-1);
}
