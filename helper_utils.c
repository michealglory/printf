#include "main.h"

/**
 * can_be_printed - Checks if a character can be printed.
 *
 * This function determines whether a given character can be printed or not.
 * It checks if the ASCII value of the character falls within the range of
 * printable characters,
 * which is between ASCII value 32 (space) and ASCII value 126 (tilde).
 *
 * @c: The character to be checked for printability.
 * Return: 1 if the character is printable, 0 otherwise.
 */
int can_be_printed(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * add_hexadecimal - Add hexadecimal representation of an ASCII character
 * to a buffer.
 *
 * This function takes an ASCII character and adds its hexadecimal
 * representation to a character buffer. The buffer should be large
 * enough to accommodate the additional characters (at least 4 characters).
 * The function writes the hexadecimal representation in the format "\\xHH",
 * where "HH" represents the hexadecimal digits.
 *
 * @ascii: The ASCII character whose hexadecimal representation needs
 * to be added.
 * @buffer: The character buffer where the hexadecimal representation
 * will be added.
 * @i: The index in the buffer where the hexadecimal representation
 * will start.
 * Return: The number of characters added to the buffer (always 3 in
 * this case).
 */
int add_hexadecimal(char ascii, char buffer[], int i)
{
	char map_array[] = "0123456789ABCDEF";

	if (ascii < 0)
	{
		ascii *= -1;
	}
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_array[ascii / 16];
	buffer[i] = map_array[ascii % 16];
	return (3);
}

/**
 * is_a_digit - Check if a character is a digit.
 *
 * This function determines whether a given character is a digit or not.
 * It checks if the character falls within the ASCII range of digits,
 * which is from '0' to '9' (inclusive).
 *
 * @c: The character to be checked.
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int is_a_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


/**
 * cast_num_to_size - Cast a number to a specific size based on the given
 * size parameter.
 *
 * This function takes a long integer 'num' and an integer 'size' as input
 * parameters and returns the 'num' casted to the specified size. The 'size'
 * parameter is used to determine the target size of the return value, and
 * it should be one of the predefined size constants 'S_LONG', 'S_SHORT', or
 * 'S_INT'.
 *
 * @num: The long integer to be casted.
 * @size: The target size for the return value. It should be one of the
 * following:
 *             - 'S_LONG': The function returns 'num' as it is (no casting).
 *             - 'S_SHORT': The function returns 'num' casted to a short
 * integer.
 *             - 'S_INT': The function returns 'num' casted to a regular
 * integer.
 *
 * Return: The 'num' casted to the specified size based on the 'size'
 * parameter:
 *         - If 'size' is 'S_LONG', it returns 'num' as a long integer
 * (no casting).
 *         - If 'size' is 'S_SHORT', it returns 'num' casted to a short
 * integer.
 *         - If 'size' is 'S_INT', it returns 'num' casted to a regular
 * integer.
 */
long int cast_num_to_size(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * cast_num_to_size_unsgnd - Cast an unsigned number to a specific
 * size based on the given size
 * parameter.
 *
 * This function takes an unsigned long integer 'num' and an integer 'size'
 * as input parameters
 * and returns 'num' casted to the specified size. The 'size' parameter is
 * used to determine the target size of the return value, and it should be
 * one of the predefined size constants 'S_LONG',
 * 'S_SHORT', or 'S_INT'.
 *
 * @num: The unsigned long integer to be casted.
 * @size: The target size for the return value. It should be one of
 * the following:
 *             - 'S_LONG': The function returns 'num' as an unsigned long
 * integer (no casting).
 *             - 'S_SHORT': The function returns 'num' casted to an
 * unsigned short integer.
 *             - 'S_INT': The function returns 'num' casted to an
 * unsigned regular integer.
 *
 * Return: The 'num' casted to the specified size based on the 'size'
 * parameter:
 *         - If 'size' is 'S_LONG', it returns 'num' as an unsigned
 * long integer (no casting).
 *         - If 'size' is 'S_SHORT', it returns 'num' casted to an
 * unsigned short integer.
 *         - If 'size' is 'S_INT', it returns 'num' casted to an
 * unsigned regular integer.
 */
long int cast_num_to_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
