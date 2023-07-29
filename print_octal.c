#include "main.h"

/**
 * print_octal - Converts an unsigned integer to its octal representation
 *               and writes it to a character buffer.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer where the octal representation will be
 * stored.
 * @flags: An integer representing formatting flags (e.g., F_HASH).
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the octal representation.
 * @size: The size of the number (e.g., sizeof(unsigned long int)).
 *
 * Return: The number of characters written to the buffer.
 */

int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int original_num = number;
	int index = BUFF_SIZE - 2;

	UNUSED(width);
	number = cast_num_to_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[index--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[index--] = (number % 8) + '0';
		number /= 8;
	}
	if (flags & F_HASH && original_num != 0)
	{
		buffer[index--] = '0';
	}
	index++;
	return (write_unsigned_to_stout(0, index, buffer,
				flags, width, precision, size));
}
