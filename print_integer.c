#include "main.h"
/**
* print_integer - Prints an integer to the
* standard output.
* @i: The va_list containing the integer to print.
* Return: The number of characters printed.
*/
int print_integer(va_list i)
{
	int va_app, count = 0, num;
	int length, pow_of_ten, index, numeral;

	va_app = va_arg(i, int);
	if (va_app != 0)
	{
		if (va_app < 0)
		{
			_putchar('-');
			count++;
		}
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
			if (va_app < 0)
				_putchar((numeral * -1) + 48);
			else
				_putchar(numeral + '0');
			count++;
			va_app -= numeral * pow_of_ten;
			pow_of_ten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
