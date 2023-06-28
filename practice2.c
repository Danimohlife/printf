#include "main.h"
/**
 * lower_h - output unsigned numbers in lowercase
 * @ap: the argument pointer
 * @user: the argument
 * Return: bytes returned
 */
int lower_h(va_list ap, arg_t *user)
{
	unsigned long i;
	int a = 0;
	char *string;

	if (user->last_flag)
		i = (unsigned long)va_arg(ap, unsigned long);
	else if (user->)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else
		i = (unsigned int)va_arg(ap, unsigned int);
	string = converter(i, 16, UNSIGNED_CON | LOWERCASE_CON, user);
	if (user->third_flag && i)
	{
		*--string = 'x';
		*--string = '0';
	}
	user->unsign = 1;
	return (a += display_numb(string, user));
}
/**
 * upper_h - output unsigned numbers in uppercase
 * @ap: the argument pointer
 * @user: the argument
 * Return: bytes returned
 */
int upper_h(va_list ap, arg_t *user)
{
	unsigned long i;
	int a = 0;
	char *string;

	if (user->last_flag)
		i = (unsigned long)va_arg(ap, unsigned long);
	else if (user->height_mode)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else
		i = (unsigned int)va_arg(ap, unsigned int);
	string = converter(i, 16, UNSIGNED_CON, user);
	if (user->third_flag && i)
	{
		*--string = 'X';
		*--string = '0';
	}
	user->unsign = 1;
	return (a += display_numb(string, user));
}
/**
 * binary_func - binary number
 * @ap: the argument pointer
 * @user: the argument
 * Return: bytes returned
 */
int binary_func(va_list ap, arg_t *user)
{
	unsigned int a;
	char *string;
	int b = 0;

	a = va_arg(ap, unsigned int);
	string = converter(a, 2, UNSIGNED_CON, user);

	if (user->third_flag && a)
		*--string = '0';
	user->unsign = 1;
	return (b += display_numb(string, user));
}
/**
 * octal_func - octal numbers
 * @ap: the argument pointer
 * @user: the argument
 * Return: bytes returned
 */
int octal_func(va_list ap, arg_t *user)
{
	unsigned long i;
	char *string;
	int c = 0;

	if (user->last_flag)
		i = (unsigned long)va_arg(ap, unsigned long);
	else if (user->height_mode)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else
		i = (unsigned int)va_arg(ap, unsigned int);
	string = converter(i, 8, UNSIGNED_CON, user);
	if (user->third_flag && i)
		*--string = '0';
	user->unsign = 1;
	return (c += display_numb(string, user));
}
