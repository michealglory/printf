#include "main.h"

/**
 * write_number_to_stout - Writes the number representation (integer)
 * to the standard output.
 *
 * @is_negative: A flag indicating if the number is negative (1 for negative,
 * 0 for non-negative).
 * @ind: The index of the buffer where the number representation starts.
 * @buffer: The character buffer containing the number representation.
 * @flags: An integer representing formatting flags (e.g., F_ZERO,
 * F_MINUS, F_PLUS, F_SPACE).
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the number representation
 * (precision).
 * @size: The size of the number (unused in this function).
 *
 * Return: The number of characters written to the standard output.
 *
 * Note:
 * - The write_number_to_stout function is used for formatting and printing
 * number representations (integers).
 * - It handles padding, width, precision, and additional characters
 * (e.g., '-', '+', ' ') to be included in the output.
 * - The function directly writes the representation to the standard output
 * and returns the number of characters printed.
 * - The buffer contains the number representation, and ind is the starting
 * index of the representation in the buffer.
 */

int write_number_to_stout(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	char padding = ' ', extra_char = 0;
	int count = BUFF_SIZE - ind - 1;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		padding = '0';
	}
	if (is_negative)
	{
		extra_char = '-';
	}
	else if (flags & F_PLUS)
	{
		extra_char = '+';
	}
	else if (flags & F_SPACE)
	{
		extra_char = ' ';
	}
	return (write_num_to_stout(ind, buffer, flags, width, precision,
				count, padding, extra_char));
}
/**
 * write_num_to_stout - Writes the number representation to the standard
 * output.
 *
 * @ind: The index of the buffer where the number representation starts.
 * @buffer: The character buffer containing the number representation.
 * @flags: An integer representing formatting flags (e.g., F_ZERO, F_MINUS).
 * @width: The minimum width of the output, formatted accordingly.
 * @prec: The number of digits to display for the number representation
 * (precision).
 * @length: The length of the number representation.
 * @padd: The padding character (' ' or '0') used for formatting.
 * @extra_c: An extra character to be added to the representation
 * (e.g., '+', ' ').
 *
 * Return: The number of characters written to the standard output.
 *
 * Note:
 * - The write_num_to_stout function is used for formatting and printing
 * number representations (integers).
 * - It handles padding, width, precision, and additional characters
 * (e.g., '+', '0') to be included in the output.
 * - The function directly writes the representation to the standard
 * output and returns the number of characters printed.
 * - The buffer contains the number representation, and ind is the
 * starting index of the representation in the buffer.
 */

int write_num_to_stout(int ind, char buffer[], int flags, int width, int prec,
		int length, char padd, char extra_c)
{
	int i, padding_start = 1;

	if (prec == 0 && buffer[ind] == '0' && width == 0 && ind == BUFF_SIZE - 2)
		return (0);
	if (prec == 0 && buffer[ind] == '0' && ind == BUFF_SIZE - 2)
		buffer[ind] = padd = ' ';
	if (prec < length && prec > 0)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padding_start] = extra_c;
			return (write(1, &buffer[padding_start], i - padding_start) +
					write(1, &buffer[ind], length - (1 - padding_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
/**
 * write_unsigned_to_stout - Writes the unsigned integer representation
 * to the standard output.
 *
 * @is_negative: A flag indicating if the number is negative (unused
 * in this function).
 * @ind: The index of the buffer where the unsigned integer representation
 * starts.
 * @buffer: The character buffer containing the unsigned integer
 * representation.
 * @flags: An integer representing formatting flags (e.g., F_ZERO,
 * F_MINUS).
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display for the unsigned integer
 * representation.
 * @size: The size of the number (unused in this function).
 *
 * Return: The number of characters written to the standard output.
 *
 * Note:
 * - The write_unsigned_to_stout function is used for formatting and
 * printing the unsigned integer representation.
 * - It handles padding, width, and precision options for the output.
 * - The function directly writes the representation to the standard
 * output and returns the number of characters printed.
 * - The buffer contains the unsigned integer representation, and ind
 * is the starting index of the representation in the buffer.
 */

int write_unsigned_to_stout(int is_negative, int ind,
		char buffer[], int flags, int width, int precision, int size)
{
	int count = BUFF_SIZE - ind - 1, j = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < count)
		padding = ' ';
	while (precision > count)
	{
		buffer[--ind] = '0';
		count++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (width > count)
	{
		for (j = 0; j < width - count; j++)
			buffer[j] = padding;
		buffer[j] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], count) + write(1, &buffer[0], j));
		}
		else
		{
			return (write(1, &buffer[0], j) + write(1, &buffer[ind], count));
		}
	}
	return (write(1, &buffer[ind], count));
}

/**
 * write_pointer_to_stout - Writes the hexadecimal representation of a
 * pointer to the standard output.
 *
 * @buffer: The character buffer containing the hexadecimal
 * representation of the pointer.
 * @ind: The index of the buffer where the pointer representation starts.
 * @length: The length of the hexadecimal representation.
 * @width: The minimum width of the output, formatted accordingly.
 * @flags: An integer representing formatting flags.
 * @padd: The padding character (' ' or '0') used for formatting.
 * @extra_c: An extra character to be added to the representation
 * (e.g., '+', ' ').
 * @padd_start: The index where the padding starts in the buffer.
 *
 * Return: The number of characters written to the standard output.
 *
 * Note:
 * - The write_pointer_to_stout function is used for formatting and
 * printing the hexadecimal representation of a pointer.
 * - It handles padding, width, and additional characters (e.g.,
 * '0x', '+') to be included in the output.
 * - The function directly writes the representation to the standard
 * output and returns the number of characters printed.
 * - The buffer contains the hexadecimal representation, and ind is the
 * starting index of the representation in the buffer.
 */

int write_pointer_to_stout(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start)
{
	int j;

	if (width > length)
	{
		for (j = 3; j < width - length + 3; j++)
			buffer[j] = padd;
		buffer[j] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], j - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], j - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], j - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

