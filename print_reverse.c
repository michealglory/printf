#include "main.h"

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str_to_print;
	int index, str_count = 0;

	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);

	str_to_print = va_arg(types, char *);

	if (str_to_print == NULL)
	{
		str_to_print = ")Null(";
	}
	for (index = 0; str_to_print[index]; index++)
		;
	for (index = index - 1; index >= 0; index--)
	{
		char ch = str_to_print[index];

		write(1, &ch, 1);
		str_count++;
	}
	return (str_count);
}
