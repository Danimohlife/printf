#include "main.h"
/**
 * func_ptr - format function
 * @t: string of the format
 * Return: bytes returned
 */
int (*func_ptr(char *t))(va_list ap, arg_t *user)
{
	life function[] = {
		{"%", percentage},
		{"s", str_print},
		{"c", display_str},
		{"i", show_number},
		{"d", show_number},
		{"u", unsigned_num},
		{"b", binary_func},
		{"o", octal_func},
		{"p", _address_of},
		{"x", lower_h},
		{"X", upper_h},
		{"r", string_rev},
		{"S", string_func},
		{"R", string_rot},
		{NULL, NULL}
	};

	int a;
	for (a = 0; function[a].string; a++)
	{
		if (*t == function[a].string[0])
		{
			return (function[a].ch);
		}
	}
	return (NULL);
}
/**
 * find_func - format function
 * @t: string of the format
 * @ap: argument pointer
 * @user: the argument
 * Return: bytes returned
 */
int find_func(char *t, va_list ap, arg_t *user)
{
	int (*ch)(va_list, arg_t *) = func_ptr(t);

	if (ch)
		return (ch(ap, user));
	return (0);
}
/**
 * print_fg - flag functions
 * @t: the format string
 * @user: the argument
 * Return: valid flag
 */
int print_fg(char *t, arg_t *user)
{
	int k = 0;

	switch (*t)
	{
		case '+':
			k = user->added = 1;
			break;
		case ' ':
			k = user->space = 1;
			break;
		case '#':
			k = user->third_flag = 1;
			break;
		case '-':
			k = user->fifth_flag = 1;
			break;
		case '0':
			k = user->flag = 1;
			break;
	}
	return (k);
}
/**
 * modify_func - the modifier function
 * @t: string for format
 * @user: argument structure
 * Return: valid modifier
 */
int modify_func(char *t, arg_t *user)
{
	int k = 0;

	switch (*t)
	{
		case 'h':
			k = user->height_mode = 1;
			break;
		case 'l':
			k = user->last_flag = 1;
			break;
	}
	return (k);
}
/**
 * radius_func - width of the format string
 * @t: the format string
 * @user: the argument structure
 * @ap: the argument
 * Return: new pointer
 */
char *radius_func(char *t, arg_t *user, va_list ap)
{
	int a = 0;

	if (t == '')
	{
		a = va_arg(ap, int);
		t++;
	}
	else
	{
		while (_isdigit(*t))
			a = a * 10 + (*t++ - '0');
	}
	user->radius = a;
	return (t);
}
