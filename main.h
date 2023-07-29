#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define S_LONG 2
#define S_SHORT 1
#define F_ZERO 4
#define F_SPACE 16
#define F_HASH 8
#define F_MINUS 1
#define F_PLUS 2

/**
 * struct fmt - Struct op
 *
 * @fmt: The function format.
 * @fn: The associated function.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The correct format to use.
 * @fm_t: The associated function.
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int process_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_character(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_integer(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percentage(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);
int print_hexadecimal_lower(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_rot13(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int cal_width(const char *format, int *i, va_list list);
int process_and_return_flags(const char *format, int *i);
int cal_precision(const char *format, int *i, va_list list);
void print_buffer(char buffer[], int *buff_ind);
int calculate_size(const char *format, int *i);
int handle_write_character(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number_to_stout(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num_to_stout(int ind, char bff[], int flags, int width,
		int precision, int length, char padd, char extra_c);
int write_pointer_to_stout(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);
int write_unsigned_to_stout(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);
int can_be_printed(char);
int add_hexadecimal(char, char[], int);
int is_a_digit(char);
long int cast_num_to_size(long int num, int size);
long int cast_num_to_size_unsgnd(unsigned long int num, int size);
#endif /* MAIN_H */

