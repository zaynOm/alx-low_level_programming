#include "main.h"
/**
 * _islower - checks if the given character is in lowercase
 *
 * @c: int that holds the ascii code of the character
 *
 * Return: 1 if lowercase, 0 if not
 */
int _islower(int c)
{
	if (97 <= c && 122 >= c)
		return (1);

	return (0);
}
