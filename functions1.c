#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned int n = va_arg(types, unsigned int);
	UNUSED(buffer); UNUSED(flags); UNUSED(width);
	UNUSED(precision); UNUSED(size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write(1, &buffer[i], BUFF_SIZE - 1 - i));
}

/**
 * print_octal - Prints an unsigned number in octal
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned int n = va_arg(types, unsigned int);
	UNUSED(buffer); UNUSED(flags); UNUSED(width);
	UNUSED(precision); UNUSED(size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}
	i++;
	return (write(1, &buffer[i], BUFF_SIZE - 1 - i));
}

/**
 * print_hexadecimal - Prints in hexadecimal
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints in upper hexadecimal
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Helper to print hexadecimal in any case
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned int n = va_arg(types, unsigned int);
	UNUSED(buffer); UNUSED(flags); UNUSED(flag_ch);
	UNUSED(width); UNUSED(precision); UNUSED(size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = map_to[n % 16];
		n /= 16;
	}
	i++;
	return (write(1, &buffer[i], BUFF_SIZE - 1 - i));
}
