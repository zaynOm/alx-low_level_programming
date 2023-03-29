/**
 * _strcat - concatenates two strings
 *
 * @dest: first string
 * @src: the string to concate to dest
 *
 * Return: array of chars
 */
char *_strcat(char *dest, char *src)
{
	int j = 0, i = 0;

	while (dest[i])
		i++;

	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);

}
