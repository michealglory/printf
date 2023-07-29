#include "main.h"

/**
 * print_binary - Print binary representation of an unsigned integer.
 *
 * This function prints the binary representation of an unsigned integer
 * to the standard output.
 * The unsigned integer to be printed is obtained from the variable arguments
 * list 'types'.
 *
 * @types: The va_list containing the variable arguments (unsigned int
 * in this case).
 * @buffer: Unused parameter (not used in the function).
 * @flags: Unused parameter (not used in the function).
 * @width: Unused parameter (not used in the function).
 * @precision: Unused parameter (not used in the function).
 * @size: Unused parameter (not used in the function).
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int a[32];
	unsigned int app, number, index, total;
	int count;

	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);

	number = 2147483648;
	app = va_arg(types, unsigned int);
	a[0] = app / number;

	for (index = 1; index < 32; index++)
	{
		number /= 2;
		a[index] = (app / number) % 2;
	}
	for (index = 0, total = 0, count = 0; index < 32; index++)
	{
		total += a[index];
		if (total || index == 31)
		{
			char z = '0' + a[index];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
