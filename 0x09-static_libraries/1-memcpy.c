/**
 * _memcpy - copies memory area
 * @src: the memory area to copy from
 * @dest: the memory area to past in
 * @n: nember of bytes to copy
 *
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
