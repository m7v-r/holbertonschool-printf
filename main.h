#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct format - Structure to match specifiers with functions
 * @spec: The specifier (e.g., 'c', 's', 'd', 'i')
 * @f: The function pointer associated
 */
typedef struct format
{
	char *spec;
	int (*f)(va_list);
} fmt_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int recursive_int(unsigned int n);

#endif /* MAIN_H */
