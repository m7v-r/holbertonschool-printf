#include "main.h"

/**
 * get_print_func - selects the right function to perform the print
 * @s: the specifier
 * Return: pointer to the function or NULL
 */
int (*get_print_func(char s))(va_list)
{
	fmt_t funcs[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs[i].spec)
	{
		if (funcs[i].spec[0] == s)
			return (funcs[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*f)(va_list);

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			f = get_print_func(format[i + 1]);
			if (f)
			{
				count += f(args);
				i += 2;
				continue;
			}
			_putchar(format[i]);
			count++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
