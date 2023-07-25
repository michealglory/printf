#include "main.h"
/**
* print_unsigned - Prints an unsigned integer to
* the standard output.
* @u: unsigned number
* Descriptions: The va_list containing the unsigned
* integer to print.
* Return: The number of characters printed.
*/
int print_unsigned(va_list u)
{
	int char_count = 0;
	unsigned int length, pow_of_ten, num;
	unsigned int index, numeral, va_app;

	va_app = va_arg(u, unsigned int);
	if (va_app != 0)
	{
		num = va_app;
		length = 0;
		while (num != 0)
		{
			num /= 10;
			length++;
		}
		pow_of_ten = 1;
		for (index = 1; index <= length - 1; index++)
			pow_of_ten *= 10;
		for (index = 1; index <= length; index++)
		{
			numeral = va_app / pow_of_ten;
			_putchar(numeral + '0');
			char_count++;
			va_app -= numeral * pow_of_ten;
			pow_of_ten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (char_count);
}

