#include <stdio.h>

/**
 * main - Entry point
 * Desc: This program finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 *
 * Return: ALways 0
 */
int main(void)
{
	int i;
	unsigned long int fib1, fib2, fib1_1, fib1_2, fib2_1, fib2_2, half1, half2;

	fib1 = 1;
	fib2 = 2;

	printf("%lu", fib1);

	for (i = 0; i < 90; i++)
	{
		printf(", %lu", fib2);
		fib2 = fib2 + fib1;
		fib1 = fib2 - fib1;
	}

	fib1_1 = fib1 / 1000000000;
	fib2_1 = fib2 / 1000000000;
	fib1_2 = fib1 % 1000000000;
	fib2_2 = fib2 % 1000000000;

	for (i = 91; i < 98; ++i)
	{
		half1 = fib2_1 + (fib2_2 / 1000000000);
		half2 =  fib2_2 % 1000000000;
		printf(", %lu", half1);
		printf("%lu", half2);

		fib2_1 = fib2_1 + fib1_1;
		fib1_1 = fib2_1 - fib1_1;
		fib2_2 = fib2_2 + fib1_2;
		fib1_2 = fib2_2 - fib1_2;
	}

	printf("\n");

	return (0);
}
