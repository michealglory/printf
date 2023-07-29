#include "main.h"

/**
 * print_string - Writes a string to a character buffer with optional
 * formatting.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer (unused in this function).
 * @flags: An integer representing formatting flags (e.g., F_MINUS).
 * @width: The minimum width of the output (unused in this function).
 * @precision: The maximum number of characters to display from the
 * string (unused in this function).
 * @size: The size of the number (unused in this function).
 *
 * Return: The number of characters written to the buffer.
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str_to_print = va_arg(types, char *);
	int count = 0, i;

	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(buffer);

	if (str_to_print == NULL)
	{
		str_to_print = "(null)";
		if (precision >= 6)
			str_to_print = "      ";
	}
	while (str_to_print[count] != '\0')
		count++;
	if (precision >= 0 && precision < count)
		count = precision;
	if (width > count)
	{
		if (flags & F_MINUS)
		{
			write(1, &str_to_print[0], count);
			for (i = width - count; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - count; i > 0; i--)
				write(1, " ", 1);
			write(1, &str_to_print[0], count);
			return (width);
		}
	}
	return (write(1, str_to_print, count));
}
