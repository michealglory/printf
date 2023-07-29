#include "main.h"

/**
 * print_rot13 - Converts a string to its ROT13 (Caesar cipher)
 * representation and writes it to a character buffer.
 *
 * @types: A va_list representing the argument list.
 * @buffer: The character buffer (unused in this function).
 * @flags: An integer representing formatting flags (unused in
 * this function).
 * @width: The minimum width of the output (unused in this function).
 * @precision: The number of digits to display (unused in this function).
 * @size: The size of the number (unused in this function).
 *
 * Return: The number of characters written to the buffer.
 */

int print_rot13(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char ch;
	char *str_to_print;
	unsigned int index_i, index_j;
	int total = 0;
	char normal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str_to_print = va_arg(types, char *);
	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(buffer);
	UNUSED(precision);
	if (str_to_print == NULL)
		str_to_print = "(AHYY)";
	for (index_i = 0; str_to_print[index_i]; index_i++)
	{
		for (index_j = 0; normal[index_j]; index_j++)
		{
			if (normal[index_j] == str_to_print[index_i])
			{
				ch = rot[index_j];

				write(1, &ch, 1);
				total++;
				break;
			}
		}
		if (!normal[index_j])
		{
			ch = str_to_print[index_i];

			write(1, &ch, 1);
			total++;
		}
	}
	return (total);
}
