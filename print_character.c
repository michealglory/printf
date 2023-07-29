#include "main.h"
/**
 * print_character - Print a character with formatting options.
 *
 * This function prints a character obtained from the variable arguments
 * list 'types'using the va_arg macro. It then handles the printing process
 * with specified formatting options such as 'flags' and 'width' by calling
 * the 'handle_write_character' function.
 *
 * @types: The va_list containing the variable arguments (character in
 * this case).
 * @buffer: The character buffer where the formatted result will be
 * stored.
 * @flags: The flags specifying formatting options for the character
 * (e.g., 'F_ZERO' for zero-padding).
 * @width: The minimum width of the output, used for padding the
 * character.
 * @precision: Unused parameter (not used in the function).
 * @size: Unused parameter (not used in the function).
 *
 * Return: The number of characters printed (including the character
 * and padding).
 */
int print_character(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char character = va_arg(types, int);

	return (handle_write_character(character, buffer, flags, width,
				precision, size));
}

/**
 * handle_write_character - Handle writing a character to a buffer
 * with formatting options.
 *
 * This function writes a character 'c' to a character buffer 'buffer',
 * considering the specified formatting options such as 'flags' and 'width'.
 * The buffer will be padded with spaces or zeros based on the presence of
 * 'F_ZERO' flag. The formatted result is then written to the standard
 * output.
 *
 * @c: The character to be written to the buffer and printed.
 * @buffer: The character buffer where the formatted result will be
 * stored.
 * @flags: The flags specifying formatting options for the character
 * (e.g., 'F_ZERO' for zero-padding).
 * @width: The minimum width of the output, used for padding the
 * character (including the character itself).
 * @precision: Unused parameter (not used in the function).
 * @size: Unused parameter (not used in the function).
 *
 * Return: The number of characters printed (including the character
 * 'c' and padding).
 */
int handle_write_character(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	char padding = ' ';
	int index = 0;

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	{
		padding = '0';
	}
	buffer[index++] = c;
	buffer[index] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (index = 0; index < width - 1; index++)
		{
			buffer[BUFF_SIZE - index - 2] = padding;
		}
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - index - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - index - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
