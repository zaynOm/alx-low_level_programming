#include "main.h"

/**
 * get_bit - finds the value of a bit at a given index
 * @n: unsigned long integer
 * @index: the index, starting from 0 of the bit you want to get
 *
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long x = 1;

	while (index--)
		x <<= 1;
	if (x > n || index > 64)
		return (-1);

	return ((n & x) ? 1 : 0);
}
