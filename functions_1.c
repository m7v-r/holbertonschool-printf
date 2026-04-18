#include "main.h"

/**
 * recursive_int - prints digits of an integer using recursion
 * @n: unsigned integer to print
 * Return: number of digits printed
 */
int recursive_int(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += recursive_int(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_int - prints an integer
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	count += recursive_int(num);
	return (count);
}
