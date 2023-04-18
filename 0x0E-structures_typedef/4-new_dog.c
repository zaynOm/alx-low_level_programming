#include <stdlib.h>
#include "dog.h"
/**
 * _strlen - returns the lenth of a string
 * @str: a pointer that points to the first item of a string
 *
 * Return: the lenth of @str
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i + 1);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: array of chars
 * @src: a given string
 *
 * Return: the pointer to @dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: a pointer to a new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (!name || age < 0 || !owner)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (!d)
		return (NULL);

	d->name = malloc(sizeof(_strlen(name)));
	if (!d->name)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(sizeof(_strlen(owner)));
	if (!d->owner)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	d->age = age;
	_strcpy(d->owner, owner);

	return (d);
}
