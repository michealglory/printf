#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int _putchar(char c);
int _printf(const char *format, ...);
int print_character(va_list c);
int print_string(va_list s);
int print_integer(va_list i);
int print_decimal(va_list d);
int print_reverse(va_list r);
int print_binary(va_list b);
int print_unsigned(va_list u);
int print_octal(va_list o);
int print_lowercase_hex(va_list x);
int print_uppercase_hex(va_list X);
int print_rot13(va_list R);
/**
 * struct code_format - Struct format
 *
 * @sc: The specifiers
 * @f: The function associated
 */
typedef struct code_format
{
	char *sc;
	int (*f)(va_list);
} code_f;

#endif /* MAIN_H */

