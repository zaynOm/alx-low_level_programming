/**
 * _strlen - counts the length of a string
 * @str: string
 *
 * Return: length of @str
 */
int _strlen(char *str)
{
	if (!*str)
		return (0);
	return (_strlen(str + 1) + 1);
}


