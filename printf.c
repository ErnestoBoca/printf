#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * printer - prints the character
 * @args: the argument list
 * @chr: the hndler
 * Return: the number of characters printed
 */
int printer(va_list args, char chr)
{
	char c;

	if (chr == 'c')
	{
		c = va_arg(args, int);
		_putchar(c);
		return (1);
	}

	return (0);
}

/**
 * _printf - produces output according to a format.
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, cont = 0;
	char *str;
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
				cont += printer(args, format[i]);
			else if (format[i] == 's')
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
				_putchar(format[i - 1]);
				while (format[i] != '\0' && format[i] != '%')
					_putchar(format[i++]);
				i--;
			}
		}
		i++;
	}
	va_end(args);
	return (cont);
}
