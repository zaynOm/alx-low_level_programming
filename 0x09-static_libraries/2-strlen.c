/**
 * _strlen - returns the lenth of a string
 * @s: a pointer that points to the first item of a string
 *
 * Return: the lenth of a string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
