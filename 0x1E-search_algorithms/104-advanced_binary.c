#include "search_algos.h"

/**
 * recursion_binary - searches for the first occurence of a value
 * using recursion.
 * @array: Pointer to the first element of the array
 * @left: the left boundary
 * @right: the right boundary
 * @value: Value to search for
 *
 * Return: Index where the value is located, or -1 if not found
 */
int recursion_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	if (left > right)
		return (-1);

	printf("Searching in array: %d", array[left]);
	for (i = left + 1; i <= right; i++)
		printf(", %d", array[i]);
	printf("\n");

	mid = (right + left) / 2;

	if (array[mid] < value)
		left = mid + 1;
	else if (array[mid] > value)
		right = mid - 1;
	else if (array[mid - 1] == value)
		return (recursion_binary(array, 0, mid, value));
	else
		return (mid);

	return (recursion_binary(array, left, right, value));
}
/**
 * advanced_binary - searches for the first occurence of a value
 * in a sorted array using recursion.
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where the value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (recursion_binary(array, 0, size - 1, value));
}
