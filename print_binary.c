#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * print_binary - This function takes an unsigned integer
 * as a parameter and prints its binary representation to
 * the standard output.
 * @arguments: unsigned integer to be converted and printed
 * Return: The number of characters printed in the binary
 * representation.
 * Returns 1 and prints '0' if the input value is 0.
 */
int print_binary(va_list arguments)
{
	unsigned int length, binpow, i, numeral, input, temp;
	int char_count = 0;

	input = va_arg(arguments, unsigned int);
	if (input != 0)
	{
		temp = input;
		length = 0;
		while (temp != 0)
		{
			temp /= 2;
			length++;
		}
		binpow = 1;
		for (i = 1; i <= length - 1; i++)
			binpow *= 2;
		for (i = 1; i <= length; i++)
		{
			numeral = input / binpow;
			_putchar(numeral + '0');
			char_count++;
			input -= numeral * binpow;
			binpow /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (char_count);
}
