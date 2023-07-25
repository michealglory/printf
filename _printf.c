#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * find_function - Searches for the appropriate function to
 * handle a format specifier.
 * @print_format: A pointer to a character representing the
 * format specifier to be handled
 * Return: A pointer to the function that handles the format
 * specifier. If the format specifier is not found, returns NULL.
 */
int (*find_function(const char *print_format))(va_list)
{
	unsigned int item = 0;
	code_f function_list[] = {
		{"c", print_character},
		{"s", print_string},
		{"i", print_integer},
		{"d", print_decimal},
		{"r", print_reverse},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_lowercase_hex},
		{"X", print_uppercase_hex},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (function_list[item].sc)
	{
		if (function_list[item].sc[0] == (*print_format))
		{
			return (function_list[item].f);
		}
		item++;
	}
	return (NULL);
}
/**
 * _printf - Custom implementation of the printf function
 * that prints formatted text.
 *
 * @print_format: The format string containing the text to
 *  print along with optional
 *  format specifiers.
 *  Format specifiers are denoted by '%' and
 *  are followed by conversion
 *  characters like 'c', 's', 'd', 'i', 'x',
 *  'X', 'o', 'u', and '%'.
 *  Any other characters in the format string
 *  are printed as is.
 *  Note: It does not support width, precision,
 *  or other advanced
 *  printf functionalities.
 * @...: Variable number of arguments to be formatted and
 *  printed according to the
 *  format specifiers in the format string.
 *
 * Return: The total number of characters printed (excluding
 * the null terminator),
 * or -1 if an error occurs or the format string is NULL.
 */
int _printf(const char *print_format, ...)
{
	va_list va_app;
	int (*func)(va_list);
	unsigned int i = 0, print_count = 0;

	if (print_format == NULL)
	{
		return (-1);
	}
	va_start(va_app, print_format);
	while (print_format[i])
	{
		while (print_format[i] != '%' && print_format[i])
		{
			_putchar(print_format[i]);
			print_count++;
			i++;
		}
		if (print_format[i] == '\0')
		{
			return (print_count);
		}
		func = find_function(&print_format[i + 1]);
		if (func != NULL)
		{
			print_count += func(va_app);
			i += 2;
			continue;
		}
		if (!print_format[i + 1])
			return (-1);
		_putchar(print_format[i]);
		print_count++;
		if (print_format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(va_app);
	return (print_count);
}

