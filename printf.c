#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str, c;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str != '\0')
				{
					write(1, str, 1);
					str++;
					count++;
				}
			} else if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			} else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
		} else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
