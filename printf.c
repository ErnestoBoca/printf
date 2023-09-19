#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - produces output according to a format.
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, cont = 0;
	char *str, c;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			cont++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				cont++;
			} else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				_puts(str);
				cont += _strlen(str);
			} else if (format[i] == '%')
			{
				_putchar('%');
				cont++;
			} else
			{
				return (-1);
			}
		}
		i++;
	}
	va_end(args);
	return (cont);
}
