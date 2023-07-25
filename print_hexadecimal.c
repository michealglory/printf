#include "main.h"
/**
 * print_hex - Prints an unsigned integer in hexadecimal
 * format to stdout.
 *
 * @n: The unsigned integer to be printed in hexadecimal
 *     format.
 * @c: An integer indicating the letter case for
 * 	   alphabetic characters.
 *     If c is non-zero, uppercase letters (A-F) are used.
 *     If c is zero,
 *     lowercase letters (a-f) are used.
 *
 * Return: The number of characters printed.
 */
int print_hex(unsigned int n, unsigned int c)
{
	char diff;
	int int_count = 0;
	unsigned int length, pow_of_ten, index, numeral, number;

	if (n != 0)
	{
		number = n;
		length = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (number != 0)
		{
			number /= 16;
			length++;
		}
		pow_of_ten = 1;
		for (index = 1; index <= length - 1; index++)
			pow_of_ten *= 16;
		for (index = 1; index <= length; index++)
		{
			numeral = n / pow_of_ten;
			if (numeral < 10)
				_putchar(numeral + '0');
			else
				_putchar(numeral + '0' + diff);
			int_count++;
			n -= numeral * pow_of_ten;
			pow_of_ten /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (int_count);
}
/**
* print_lowercase_hex - Prints an unsigned integer to
* lowercase hexadecimal
* format to stdout.
* @x: unsigned int to print
* Return: The number of characters printed.
*/
int print_lowercase_hex(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
/**
* print_uppercase_hex - Prints an unsigned integer to
* uppercase hexadecimal
*
* @X: unsigned int to print
* Return: The number of characters printed.
*/
int print_uppercase_hex(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}

