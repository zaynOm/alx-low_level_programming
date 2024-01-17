#include "search_algos.h"
#include <math.h>

/**
 * binary_search_range - searches for a value in array interval.
 * @array: Pointer to the first element of the array
 * @low: start of the interval
 * @high: end of the interval
 * @value: Value to search for
 *
 * Return: Index where the value is located, or -1 if not found
 */
int binary_search_range(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	while (low <= high)
	{
		printf("Searching in array: %d", array[low]);
		for (i = low + 1; i <= high; i++)
			printf(", %d", array[i]);
		printf("\n");

		mid = (low + high) / 2;

		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid);
	}

	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array using
 * Exponentail search algorithm.
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where the value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t min, bound = 1;

	if (!array)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	min = (bound < size) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, min);

	return (binary_search_range(array, bound / 2, min, value));
}
