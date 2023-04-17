#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog with 3 members
 * @name: dog name
 * @age: dog age
 * @owner: name of the dog owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
