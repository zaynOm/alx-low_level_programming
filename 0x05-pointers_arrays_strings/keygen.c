#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - random password generator
 */
int main(void)
{
	int i, total = 0;
	char pw[99];

	srand(time(0));

	for (i = 0; total <= 2772; i++)
	{
		pw[i] = rand() % 94 + 33;
		total += pw[i]; 
		putchar(pw[i]);
	}

	return (0);
}
