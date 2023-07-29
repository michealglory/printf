#include "main.h"
/**
 * process_and_return_flags - Process and return flags from a format
 * specifier in a printf-like function.
 *
 * This function parses the format string starting from the position given
 * by 'i', and extracts the flags information from the format specifier. The
 * format string is expected to be in a printf-like format.
 *
 * @format: The format string to be parsed.
 * @i: Pointer to the current position in the format string.
 *
 * Return: The calculated flags value extracted from the format specifier.
 */
int process_and_return_flags(const char *format, int *i)
{
	int flags = 0;
	int index, current;
	const int flags_array[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	const char flags_char[] = {'-', '+', '0', '#', ' ', '\0'};

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		for (index = 0; flags_char[index] != '\0'; index++)
			if (format[current] == flags_char[index])
			{
				flags |= flags_array[index];
				break;
			}
		if (flags_char[index] == 0)
		{
			break;
		}
	}
	*i = current - 1;
	return (flags);
}

/**
 * cal_precision - Calculate the precision from a format specifier in
 * a printf-like function.
 *
 * This function parses the format string starting from the position given
 * by 'i', and extracts the precision information from the format specifier.
 * The format string is expected to be in a printf-like format.
 *
 * @format: The format string to be parsed.
 * @i: Pointer to the current position in the format string.
 * @list: The va_list object used for variable arguments (if applicable).
 *
 * Return: The calculated precision value extracted from the format specifier.
 *         If no precision is specified, the function returns -1.
 */
int cal_precision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int current = *i + 1;

	if (format[current] != '.')
	{
		return (precision);
	}
	precision = 0;
	for (current += 1; format[current] != '\0'; current++)
	{
		if (is_a_digit(format[current]))
		{
			precision *= 10;
			precision += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = current - 1;
	return (precision);
}

/**
 * calculate_size - Calculate the size from a format specifier in a
 * printf-like function.
 *
 * This function parses the format string starting from the position given
 * by 'i', and extracts the size information from the format specifier.
 * The format string is expected to be in a printf-like format.
 *
 * @format: The format string to be parsed.
 * @i: Pointer to the current position in the format string.
 *
 * Return: The calculated size value extracted from the format specifier.
 */
int calculate_size(const char *format, int *i)
{
	int size = 0;
	int current = *i + 1;

	if (format[current] == 'l')
	{
		size = S_LONG;
	}
	else if (format[current] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*i = current - 1;
	}
	else
	{
		*i = current;
	}
	return (size);
}


/**
 * cal_width - Calculate the width from a format specifier in a
 * printf-like function.
 *
 * This function parses the format string starting from the position given
 * by 'i', and extracts the width information from the format specifier.
 * The format string is expected to be in a printf-like format.
 *
 * @format: The format string to be parsed.
 * @i: Pointer to the current position in the format string.
 * @list: The va_list object used for variable arguments (if applicable).
 *
 * Return: The calculated width value extracted from the format specifier.
 */
int cal_width(const char *format, int *i, va_list list)
{
	int width = 0;
	int current;

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		if (is_a_digit(format[current]))
		{
			width *= 10;
			width += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = current - 1;
	return (width);
}
