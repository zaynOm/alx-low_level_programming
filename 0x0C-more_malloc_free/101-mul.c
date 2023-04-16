#include <stdlib.h>
#include <stdio.h>
/**
 * exit_error - prints Error then it exits with 98 code
 */
void exit_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * length - counts the length of a string
 * @str: a string
 *
 * Return: the length of str
 */
int length(char *str)
{
	int l = 0;

	while (str[l])
		l++;
	return (l);
}

/**
 * is_digit - checks wether a string is a number or not
 * @str: a string
 * @len: the length of str
 *
 * Return: 0 if str contains a non digit character, otherwise 1
 */
int is_digit(char *str, int len)
{
	while (len >= 0)
	{
		if (str[len] < '0' || '9' < str[len])
			return (0);
		len--;
	}
	return (1);
}

/**
 * _atoi - converts a string of numbers into an array of numbers
 * @s: a string
 * @len: length of s
 *
 * Return: a pointer to the created array of numbers
 */
int *_atoi(char *s, int len)
{
	int i = 0;
	int *num;

	num = malloc(sizeof(*num) * len);
	if (!num)
		exit_error();
	while (s[i])
	{
		if (s[i] > 47 && s[i] < 58)
			num[i] = s[i] - 48;
		i++;
	}
	return (num);
}

/**
 * print_result - prints result of multiplication followed by a new line
 * @res: array of integers
 * @len1: integer
 * @len2: integer
 */
void print_result(int *res, int len1, int len2)
{
	int i, not_zero = 0;

	for (i = 0; i < len1 + len2; i++)
	{
		if (res[i])
			not_zero = 1;
		if (not_zero)
			printf("%d", res[i]);
		else if (i == len1 + len2 - 1)
			printf("0");
	}
	printf("\n");
}

/**
 * main - entry point
 * Desc: calculates the multiplication of two numbers stored in two strings
 * @ac: integer
 * @av: array of strings
 *
 * Return: 0 on success, otherwisw 98
 */
int main(int ac, char **av)
{
	int *num1, *num2, *res, len1, len2, dig;
	int n, i, j, k, l1, l2;

	i = j =  0;
	k = 1;

	if (ac != 3)
		exit_error();

	len1 = length(av[1]);
	len2 = length(av[2]);
	dig = is_digit(av[1], len1 - 1) + is_digit(av[2], len2 - 1);
	if (dig != 2)
		exit_error();
	num1 = _atoi(av[1], len1);
	num2 = _atoi(av[2], len2);
	res = malloc(sizeof(*res) * (len1 + len2));
	if (!res)
		exit_error();
	for (; res[i]; i++)
		res[i] = 0;

	for (l1 = len1; l1 > 0; l1--)
	{
		i = len1 + len2 - k;
		for (l2 = len2; l2 > 0; l2--, i--)
		{
			n = num1[l1 - 1] * num2[l2 - 1];
			res[i] += n % 10;
			res[i - 1] += n / 10 + res[i] / 10;
			res[i] = res[i] % 10;
		}
		k++;
	}
	print_result(res, len1, len2);
	free(res);
	return (0);
}
