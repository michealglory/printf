#include "main.h"
/**
* print_octal - Prints an unsigned integer in octal
* format to stdout.
* @o: The va_list containing the unsigned integer to
* print in octal format.
* Return: The number of characters printed.
*/
int print_octal(va_list o)
{
	int count = 0;
	unsigned int lenght, pow_of_ten, index, numeral, va_app, num;

	va_app = va_arg(o, unsigned int);
	if (va_app != 0)
	{
		num = va_app;
		lenght = 0;
		while (num != 0)
		{
			num /= 8;
			lenght++;
		}
		pow_of_ten = 1;
		for (index = 1; index <= lenght - 1; index++)
			pow_of_ten *= 8;
		for (index = 1; index <= lenght; index++)
		{
			numeral = va_app / pow_of_ten;
			_putchar(numeral + '0');
			count++;
			va_app -= numeral * pow_of_ten;
			pow_of_ten /= 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

