#include <stdio.h>
/**
 * print_multiples_sum - computes and prints the sum of all the multiples 
 * of 3 or 5 below 1024
 */
void print_multiples_sum(void)
{
	int i;
	int sum;


	for (i = 0; i < 1024; i++)
	{
		if (i % 3 == 0)
			sum += i;
		if (i % 5 == 0)
			sum += i;
	}

	printf("%d\n", sum);
}
