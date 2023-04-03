/**
 * _memset - fills the memory with a constant byte
 * @s: the area to fill
 * @b: the constant byte to fill s with
 * @n: number of byets to fill
 *
 * Return: a pointer to memory arae s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
