#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_int - prints an integer from va_list
 * @ap: va_list object from calling function
 * Return: integer count of characters printed
 */
int print_int(va_list ap)
{
	int *count_ptr;
	int num;

	count_ptr = malloc(sizeof(*count_ptr));

	if (!count_ptr)
		exit(-1);

	*count_ptr = 0;
	num = va_arg(ap, int);

	(*count_ptr) = print_digit(num, count_ptr);

	return (*count_ptr);
}

/**
 * print_digit - print the digits recursively
 * @num: next int in the va_arg list
 * @count: pointer to integer count digits
 * Return: pointer to integer count of character printed
 */
int print_digit(int num, int *count)
{
	if (num < 0)
	{
		if (num == INT_MIN)
		{
			(*count) += write(1, '-', 1);
			num++;
			num = -num;
			if (num / 10)
				print_digit(num / 10, count);
			(*count) += write(1, &((num % 10) + 1 + '0'), 1);
			return (*count);
		}
		else
		{
			(*count) += write('-');
			num = -num;
		}
	}
	if (num / 10)
		print_digit(num / 10, count);

	(*count) += write(1, &((num % 10) + '0'), 1);
	return (*count);
}
