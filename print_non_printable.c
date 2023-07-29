#include "main.h"

/**
 * print_non_printable - Converts non-printable characters in a string to
 * hexadecimal representation and writes the modified string to a character
 * buffer.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer where the modified string representation
 * will be stored.
 * @flags: An integer representing formatting flags (unused in this
 * function).
 * @width: The minimum width of the output (unused in this function).
 * @precision: The number of digits to display for the hexadecimal
 * representation (unused in this function).
 * @size: The size of the number (unused in this function).
 *
 * Return: The number of characters written to the buffer.
 */


int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int index = 0, diff = 0;
	char *str_to_print = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str_to_print == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str_to_print[index] != '\0')
	{
		if (can_be_printed(str_to_print[index]))
		{
			buffer[index + diff] = str_to_print[index];
		}
		else
		{
			diff += add_hexadecimal(str_to_print[index], buffer,
					index + diff);
		}
		index++;
	}
	buffer[index + diff] = '\0';
	return (write(1, buffer, index + diff));
}
