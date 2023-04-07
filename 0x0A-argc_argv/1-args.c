#include <stdio.h>
/**
 * main - prints the number of arguments passed to it
 * @argc: number of passed argument
 * @argv: pointer to a list of given arguments
 *
 * Return: Always 0
 */
int main(int argc, __attribute((unused)) char **argv)
{
	printf("%d\n", argc - 1);

	return (0);
}
