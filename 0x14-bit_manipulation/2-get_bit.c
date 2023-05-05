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
	unsigned long x;

	if (index >= 64)
		return (-1);
	x = 1UL << index;
	return ((n & x) ? 1 : 0);
}
