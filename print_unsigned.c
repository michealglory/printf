#include "main.h"

/**
 * print_unsigned - Converts an unsigned integer to its string
 * representation and writes it to a character buffer.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer where the string representation
 * will be stored.
 * @flags: An integer representing formatting flags.
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the string
 * representation.
 * @size: The size of the number (e.g., sizeof(unsigned long int)).
 *
 * Return: The number of characters written to the buffer.
 */


int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = cast_num_to_size_unsgnd(number, size);
	if (number == 0)
	{
		buffer[index--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[index--] = (number % 10) + '0';
		number /= 10;
	}
	index++;
	return (write_unsigned_to_stout(0, index, buffer, flags,
				width, precision, size));
}
