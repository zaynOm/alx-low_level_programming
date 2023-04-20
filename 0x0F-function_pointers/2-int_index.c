/**
 * int_index - searches for an integer
 * @array: array of numbers
 * @size: size of @array
 * @cmp: a function pointer used to compare values
 *
 * Return: the index of the first element if cmp dosen't return 0,
 * (-1) if there is no matche or size is less or equale to 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || !cmp || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
