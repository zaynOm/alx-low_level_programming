#include  "variadic_functions.h"
/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: the string to be printed between numbers
 * @n: number of the  passed integers
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);

	if (!separator)
		separator = "";

	for (i = 0; i < n - 1; i++)
		printf("%d%s", va_arg(ap, int), separator);
	printf("%d\n", va_arg(ap, int));
	va_end(ap);
}
