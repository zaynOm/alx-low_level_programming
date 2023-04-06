/**
 * check_palindrome - checks if s is palindrome
 * @s: a string
 * @i: incremental index
 * @j: decremental index
 *
 * Return: 1 if s is palindrome, 0 otherwise
 */
int check_palindrome(char *s, int i, int j)
{
	if (i >= j)
		return (1);

	if (s[i] != s[j])
		return (0);

	return (check_palindrome(s, i + 1, j - 1));
}

/**
 * is_palindrome - returns the result
 * @s: the string to check
 *
 * Return: 1 if a string is a palindrome and 0 if not
 */
int is_palindrome(char *s)
{
	int j = 0;

	while (s[j])
		j++;
	j--;
	return (check_palindrome(s, 0, j));

}
