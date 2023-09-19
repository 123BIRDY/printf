#include "main.h"

/**
 * put_str - function that prints a string
 * @c: the string to print
 * Return: the number of string bytes printed
 */

int put_str(char *c)
{
	int read = 0;

	if (c)
	{
		for (read = 0; c[read] != '\0'; read++)
		{
			put_chr(c[read]);
		}
	}
	return (read);
}
