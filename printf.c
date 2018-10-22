#include <stdarg.h> /* va_list, va_start, va_arg, va_end macros */
#include <stdlib.h> /* NULL macro */
#include "holberton.h" /* _putchar */

/**
 * print_char - prints a char parameter from a va_list
 * @ap: va_list from calling function
 * Return: integer count of characters printed
 */
int print_char(va_list ap)
{
	return (_putchar(va_arg(ap, int)));
}

/**
 * print_string - prints a string parameter from a va_list
 * @ap: va_list from calling function
 * Return: integer count of characters printed
 */
int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	int count = 0;

	while (str[count] != '\0')
		count += _putchar(str[count]);

	return (count);
}


/**
 * _printf - prints to stdout according to a format string
 * @format: constant string containing zero or more directives
 * Return: int number of characters printed (excluding terminating null-byte)
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	va_list ap;
	print_t funcs[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(ap, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			continue;
		}
		switch (format[++i])
		{
		case '%':
			count += _putchar('%');
			break;
		case 'c':
		case 's':
			for (j = 0; funcs[j].spec != NULL; j++)
			{
				if (format[i] == funcs[j].spec[0])
				{
					count += funcs[j].fn(ap);
					break;
				}
			}
			break;
		default:
			if (format[i] >= 7 && format[i] <= 13)
			{
				count += _putchar('%');
				count += _putchar(format[i]);
				break;
			}
			return (-1);
		}
	}
	va_end(ap);
	return (count);
}

