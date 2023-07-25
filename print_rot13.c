#include "main.h"
#include <stdio.h>
/**
  * print_rot13 - encodes a string using the ROT13
  * encryption algorithm.
  * @R: The va_list containing the string to
  * print using ROT13.
  * Return: The number of characters printed.
  */
int print_rot13(va_list R)
{
	char *rev;
	int j, i, char_count = 0;
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";

	rev = va_arg(R, char *);
	if (rev == NULL)
	{
		rev = "(null)";
	}
	for (j = 0; rev[j] != '\0'; j++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (rev[j] == input[i])
			{
				char_count++;
				_putchar(output[i]);
				break;
			}
		}
	}
	return (char_count);
}

