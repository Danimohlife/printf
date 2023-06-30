#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

/**
 * struct be_specified - name struct with typef
 * @added: addition
 * @unsign: most not less than 0
 * @space: space char
 * @third_flag: base
 * @precise: precision
 * @radius: for width
 * @flag: for empty
 * @fifth_flag: oth
 * @last_flag: last on line
 * @height_mode: moder
 */
typedef struct be_specified
{
	unsigned int unsign		: 1;

	unsigned int added		: 1;
	unsigned int space		: 1;
	unsigned int third_flag		: 1;
	unsigned int flag		: 1;
	unsigned int fifth_flag		: 1;

	unsigned int radius;
	unsigned int precise;

	unsigned int height_mode		: 1;
	unsigned int last_flag		: 1;
} arg_t;
/**
 * struct user - point struct
 * @string: str reference
 * @ch: pointer func in struc
 */
typedef struct user
{
	char *string;
	int (*ch)(va_list, arg_t *);
} life;

#define BUFF -1

#define BUFF_SIZE 1024
#define LOWERCASE_CON	1

#define PRINT_STARTER {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define UNSIGNED_CON	2

#define EMPTY "(null)"

/*Start of fuction prototype*/
char *converter(long int, int, int);
char *radius_func(char *, arg_t *, va_list);
char *specifier_collec(char *, arg_t *, va_list);

int (*func_ptr(char *))(va_list, arg_t *);
int print_fg(char *, arg_t *);
int modify_func(char *, arg_t *);

int find_func(char *, va_list, arg_t *);
int _printf(const char *format, ...);

int upper_h(va_list, arg_t *);
int binary_func(va_list, arg_t *);
int octal_func(va_list, arg_t *);

int lower_h(va_list, arg_t *);
int string_rot(va_list, arg_t *);
int print_rev(va_list, arg_t *);

int frint(char *, char *, char *);
int shift_r_num(char, arg_t);
int shift_l_num(char, arg_t);

int display_numb(char, arg_t *);
int _address_of(va_list, arg_t);
int unsigned_num(va_list, arg_t *);

int display_str(va_list, arg_t);
int string_func(va_list, arg_t);
int percentage(va_list, arg_t);

int show_number(va_list, arg_t);
int str_print(va_list, arg_t);
void _puts(char *);

int _isdigit(int);
int _putchar(int);
int _strlen(char);

void callstruct(arg_t *);

#endif
