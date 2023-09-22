#include "main.h"
/**
 * _puts -  prints a string, followed by a new line
 * @str: pointer to the string that will be printed
 * Return: nothing
 */
void _puts(char *str)
{
	int chr, i;

	chr = *str;
	i = 0;
	while (chr != '\0')
	{
		_putchar(chr);
		i++;
		chr = *(i + str);
	}
}
