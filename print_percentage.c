#include "main.h"

/**
 * print_percentage - Writes a percentage symbol '%' to a character buffer.
 *
 * @types: A va_list representing the argument list (unused in this
 * function).
 * @buffer: The character buffer (unused in this function).
 * @flags: An integer representing formatting flags (unused in this
 * function).
 * @width: The minimum width of the output (unused in this function).
 * @precision: The number of digits to display (unused in this function).
 * @size: The size of the number (unused in this function).
 *
 * Return: The number of characters written (always 1 for the percentage
 * symbol).
 */

int print_percentage(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(types);
	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);

	return (write(1, "%%", 1));
}
