#include <stdio.h>
/**
 * main - prints the largest prime factor of the number 612852475143
 * followed by a new line
 */
int main(void)
{
	long int num = 1231952;
	int i, j, prime;

	for (i = 2; i <= num; i++)
	{
		if (num % i != 0)
			continue;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				prime = i;
		}
		printf("%u\n", i);
	}
	return (0);
}

int factor(int x)
{

}
