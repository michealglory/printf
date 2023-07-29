#include "main.h"

/**
 * print_integer - Converts an integer to its string representation and
 * writes it to a character buffer.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer where the integer representation will
 * be stored.
 * @flags: An integer representing formatting flags.
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the integer
 * representation.
 * @size: The size of the number (e.g., sizeof(long int)).
 *
 * Return: The number of characters written to the buffer.
 */

int print_integer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int is_negative_number = 0;
	int index = BUFF_SIZE - 2;
	long int va_app = va_arg(types, long int);
	unsigned long int number;

	va_app = cast_num_to_size(va_app, size);

	if (va_app == 0)
		buffer[index--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)va_app;
	if (va_app < 0)
	{
		number = (unsigned long int)((-1) * va_app);
		is_negative_number = 1;
	}
	while (number > 0)
	{
		buffer[index--] = (number % 10) + '0';
		number /= 10;
	}
	index++;
	return (write_number_to_stout(is_negative_number, index, buffer, flags,
				width, precision, size));
}
