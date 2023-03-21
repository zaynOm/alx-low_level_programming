#include "main.h"
/**
 * _isalpha - checks if the given int is for an alphabitic character
 * @c: int that has the ascii decimal of a character
 *
 * Return: 1 if @c is alphabitic, 0 if not
 */
int _isalpha(int c)
{
	if (65 <= c && 90 >= c)
		return (1);
	if (97 <= c && 122 >= c)
		return (1);

	return (0);
}
