/**
 * find_sqrt - looks for natural square root of n
 * @n: an integer
 * @x: an integer
 *
 * Return: the square root
 */
int find_sqrt(int n, int x)
{
	if (x < 1)
		return (-1);

	if (x * x == n)
		return (x);

	return (find_sqrt(n, x - 1));

}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: an integer
 *
 * Return: the natural square root, or -1 if no square root was found
 */
int _sqrt_recursion(int n)
{
	return (find_sqrt(n, n));
}
