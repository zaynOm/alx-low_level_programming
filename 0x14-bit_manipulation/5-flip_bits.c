#include "main.h"

/**
 * flip_bits - finds the number of bits you would need to flip to get
 * from one number to another.
 * @n: original number
 * @m: number to convert to
 *
 * Return: the number of bits the need to flip to convert numbers
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long x = n ^ m;
	int count = 0;

	while (x)
	{
		count += x & 1;
		x >>= 1;
	}
	return (count);

}
