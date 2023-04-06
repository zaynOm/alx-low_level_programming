/**
 * prime_check - checks if n is a prime number
 * @n: number to check
 * @i: iterator number
 *
 * Return: 1 if n is prime, otherwise 0
 */
int prime_check(int n, int i)
{
	if (n == 2)
		return (1);

	if (n <= 1 || n % i == 0)
		return (0);

	if (i > n / 2)
		return (1);

	return (prime_check(n, i + 1));
}


/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * otherwise return 0
 * @n: number to check
 *
 * Return: 1 if n is a prime number, otherwise 0
 *
 */
int is_prime_number(int n)
{
	return (prime_check(n, 2));
}
