/**
 * rand - custom rand to win the Giga Millions
 *
 * Return: a number from the list each time it's called
 */
int rand()
{
	static int i;
	int nums[] = {8, 8, 7, 9, 23, 74};

	return (unsigned int)nums[i++];
}

