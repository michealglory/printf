#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
*print_reverse - Prints the reverse of a
* string to stdout.
*@r: The va_list containing the string to
* print in reverse.
*Return: The number of characters printed.
*/
int print_reverse(va_list r)
{
	int i, j = 0;
	char *va_st_app;

	va_st_app = va_arg(r, char *);
	if (va_st_app == NULL)
	{
		va_st_app = ")llun(";
	}
	for (i = 0; va_st_app[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(va_st_app[i]);
		j++;
	}
	return (j);
}
