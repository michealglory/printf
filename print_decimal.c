#include "main.h"
/**
 * print_decimal - Prints an integer as decimal to the
 * standard output.
 *
 * @d: The va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_decimal(va_list d)
{
	int va_app, count = 0, init_va_app, dec_lenght;
	int pow_of_ten, index, current_digit;

	va_app = va_arg(d, int);
	if (va_app != 0)
	{
		if (va_app < 0)
			_putchar('-');
		count++;
		init_va_app = va_app;
		dec_lenght = 0;
		while (init_va_app != 0)
		{
			init_va_app /= 10;
			dec_lenght++;
		}
		pow_of_ten = 1;
		for (index = 1; index <= dec_lenght - 1; index++)
			pow_of_ten *= 10;
		for (index = 1; index <= dec_lenght; index++)
		{
			current_digit = va_app / pow_of_ten;
			if (va_app < 0)
				_putchar((current_digit * -1) + 48);
			else
				_putchar(current_digit + '0');
			count++;
			va_app -= current_digit * pow_of_ten;
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
