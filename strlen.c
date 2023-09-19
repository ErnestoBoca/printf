#include "main.h"
/**
 * _strlen - calculates the length of a string.
 * @s: the pointer to the string
 * Return: the length of a string.
 */
int _strlen(char *s)
{
	int i, len;

	i = *s;
	len = 0;
	while (i != '\0')
	{
		len++;
		i = *(s + len);
	}
	return (len);
}
