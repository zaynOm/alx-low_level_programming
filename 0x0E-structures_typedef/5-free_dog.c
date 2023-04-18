#include <stdlib.h>
#include "dog.h"
/**
 * free_dog - frees dogs
 * @d: a dog
 */
void free_dog(dog_t *d)
{
	if (d)
		free(d);
}
