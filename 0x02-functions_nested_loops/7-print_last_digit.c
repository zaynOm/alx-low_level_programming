#include "main.h"
/**
 * print_last_digit - prints last digit of a number
 * @num: a given decimal number
 *
 * Return: the value of the last digit
 */
int print_last_digit(int num)
{
	int result;

	result = num % 10;

	if (result < 0)
		result = result * -1;

	_putchar(result + '0');

	return (result);
}
