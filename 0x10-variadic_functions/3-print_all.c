#include "variadic_functions.h"
/**
 * print_all - prints anything.
 * @format: a list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int end, i = 0;
	char *s;

	va_start(ap, format);

	while (format[i] && format)
	{
		end = 0;
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(ap, int));
				break;
			case 'i':
				printf("%d", va_arg(ap, int));
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				break;
			case 's':
				s = va_arg(ap, char *);
				if (s)
				{
					printf("%s", s);
					break;
				}
				printf("(nil)");
				break;
			default:
				end = 1;
				break;
		}
		if (format[i + 1] != '\0' && end != 1)
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(ap);
}
