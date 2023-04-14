#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min: the starting number
 * @max: the last number
 *
 * Return: a pointer to the new created array
 */
int *array_range(int min, int max)
{
	int *nums;
	int i = 0;

	if (min > max)
		return (NULL);

	nums = malloc(sizeof(int) * (max - min + 1));
	if (!nums)
		return (NULL);

	while (min <= max)
	{
		nums[i] = min;
		min++;
		i++;
	}
	return (nums);
}
