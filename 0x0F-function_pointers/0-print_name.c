/**
 * print_name - prints a name
 * @name: the name to print
 * @f: a function pointer
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
