#include "main.h"
/**
 * islower - checks if the given character is in lowercase
 *
 * Return: 1 if lowercase, 0 if not
 */
int _islower(int c)
{
	if (97 <= c && c <=122)
		return (1);

	return (0);
}
