#include "main.h"

/**
 * print_hexadecimal_lower - Converts an unsigned integer to its lowercase
 * hexadecimal representation and writes it to a character buffer.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer where the hexadecimal representation
 * will be stored.
 * @flags: An integer representing formatting flags.
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the hexadecimal
 * representation.
 * @size: The size of the number (e.g., sizeof(unsigned long int)).
 *
 * Return: The number of characters written to the buffer.
 */

int print_hexadecimal_lower(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexadecimal_upper - Converts an unsigned integer to its uppercase
 * hexadecimal representation and writes it to a character buffer.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer where the hexadecimal representation
 * will be stored.
 * @flags: An integer representing formatting flags.
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the hexadecimal
 * representation.
 * @size: The size of the number (e.g., sizeof(unsigned long int)).
 *
 * Return: The number of characters written to the buffer.
 */

int print_hexadecimal_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_hexa - Converts an unsigned integer to its hexadecimal \
 * representation and writes it to a character buffer.
 *
 * @types: A va_list representing the argument list.
 * @map_to: An array containing the hexadecimal mapping characters
 * (0-9, A-F).
 * @buffer: The character buffer where the hexadecimal representation
 * will bestored.
 * @flags: An integer representing formatting flags (e.g., F_HASH).
 * @flag_ch: The character representing the flag (e.g., 'x' for '0x').
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the hexadecimal
 * representation.
 * @size: The size of the number (e.g., sizeof(unsigned long int)).
 *
 * Return: The number of characters written to the buffer.
 */

int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int number_old = number;
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
		buffer[index--] = map_to[number % 16];
		number /= 16;
	}
	if (flags & F_HASH && number_old != 0)
	{
		buffer[index--] = flag_ch;
		buffer[index--] = '0';
	}
	index++;
	return (write_unsigned_to_stout(0, index, buffer, flags, width,
				precision, size));
}

