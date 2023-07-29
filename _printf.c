#include "main.h"

/**
 * _printf - A custom implementation of the printf function that supports
 * basic format specifiers.
 *
 * @format: The format string containing the text to be printed along
 * with optional format specifiers.
 *          Format specifiers start with '%' followed by conversion
 * characters (e.g., %d, %s, %c).
 * @...: Optional arguments to be printed based on the format specifiers
 * in the format string.
 *
 * Return: The number of characters printed on success, or -1 on failure.
 *
 * Note:
 * - The _printf function is a custom implementation of printf that supports
 * basic format specifiers.
 * - It takes a format string and optional arguments, processes the format
 * specifiers, and prints the output accordingly.
 * - Supported format specifiers include %c (character), %s (string), %d
 * (integer), %u (unsigned integer),
 *   %o (octal), %x and %X (hexadecimal), %p (pointer), %% (percentage),
 * and %R (ROT13 encoding).
 * - Other format specifiers or advanced formatting options are not
 * supported.
 * - The function uses a buffer to accumulate the output and flushes it
 * to the standard output when needed.
 * - Returns the total number of characters printed on success, or -1 if
 * format is NULL.
 */

int _printf(const char *format, ...)
{
	int flags, size, width, precision, buffer_index = 0;
	int index, char_printed = 0, count = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buffer_index++] = format[index];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			char_printed++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = process_and_return_flags(format, &index);
			width = cal_width(format, &index, list);
			precision = cal_precision(format, &index, list);
			size = calculate_size(format, &index);
			++index;
			count = process_print(format, &index, list, buffer,
					flags, width, precision, size);
			if (count == -1)
				return (-1);
			char_printed += count;
		}
	}
	print_buffer(buffer, &buffer_index);
	va_end(list);
	return (char_printed);
}

/**
 * print_buffer - Writes the content of the character buffer to the
 * standard output.
 *
 * @buffer: The character buffer containing the content to be written.
 * @buff_ind: A pointer to the index of the buffer.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}

/**
 * process_print - Processes format specifiers and prints the
 * corresponding content.
 *
 * @fmt: The format string.
 * @ind: Pointer to the current position in the format string.
 * @list: A va_list representing the argument list.
 * @buffer: The character buffer where the content will be stored.
 * @flags: An integer representing formatting flags.
 * @width: The minimum width of the output, formatted accordingly.
 * @precision: The number of digits to display (for certain format
 * specifiers).
 * @size: The size of the number (e.g., sizeof(int)).
 *
 * Return: The number of characters written to the buffer.
 */

int process_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int index, length = 0, char_count = -1;
	fmt_t fmt_types[] = {
		{'c', print_character}, {'s', print_string},
		{'%', print_percentage}, {'i', print_integer},
		{'d', print_integer}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hexadecimal_lower}, {'X', print_hexadecimal_upper},
		{'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13},
		{'\0', NULL}};
	for (index = 0; fmt_types[index].fmt != '\0'; index++)
		if (fmt[*ind] == fmt_types[index].fmt)
			return (fmt_types[index].fn(list, buffer, flags, width,
						precision, size));
	if (fmt_types[index].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != '%' && fmt[*ind] != ' ')
				--(*ind);
			if (fmt[*ind] == ' ')
			{
				--(*ind);
			}
			return (1);
		}
		length += write(1, &fmt[*ind], 1);
		return (length);
	}
	return (char_count);
}

