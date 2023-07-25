#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_character - writes the character c to standard
 * output
 *
 * @c: The character to print
 *
 * Return: 1.
 */
int print_character(va_list c)
{
	unsigned char character;

	character = va_arg(c, int);
	_putchar(character);
	return (1);
}
/**
 * print_percentage - Prints the '%' character to the standard
 * output.
 *
 * Return: 1.
 */
int print_percentage(void)
{
	_putchar('%');
	return (1);
}

