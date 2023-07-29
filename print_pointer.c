#include "main.h"

/**
 * print_pointer - Converts a pointer to its hexadecimal representation and
 * writes it to a character buffer.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer where the hexadecimal representation will
 * be stored.
 * @flags: An integer representing formatting flags (e.g., F_ZERO, F_MINUS,
 * F_PLUS, F_SPACE).
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the hexadecimal
 * representation (unused in this function).
 * @size: The size of the number (unused in this function).
 *
 * Return: The number of characters written to the buffer.
 */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_char = 0, padding = ' ';
	int index = BUFF_SIZE - 2, length = 2, padding_start = 1;
	unsigned long address_of_numb;
	void *addres = va_arg(types, void *);
	char mapping_array[] = "0123456789abcdef";

	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	if (addres == NULL)
	{
		return (write(1, "NULL", 4));
	}
	buffer[BUFF_SIZE - 1] = '\0';
	address_of_numb = (unsigned long)addres;

	while (address_of_numb > 0)
	{
		buffer[index--] = mapping_array[address_of_numb % 16];
		address_of_numb /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
	{
		extra_char = '+', length++;
	}
	else if (flags & F_SPACE)
	{
		extra_char = ' ', length++;
	}
	index++;
	return (write_pointer_to_stout(buffer, index, length, width, flags, padding,
				extra_char, padding_start));
}
