#include "main.h"
/**
 * display_str - prints character
 * @ap: argument pointer
 * @user: the argument
 * Return: number chars printed
 */
int display_str(va_list ap, arg_t *user)
{
	char len_str = ' ';
	unsigned int len = 1, add = 0, ch = va_arg(ap, int);

	if (user->fifth_flag)
		add = add + _putchar(ch);
	while (len++ < user->radius)
		add = add + _putchar(len_str);
	if (!user->fifth_flag)
		add = add + _putchar(ch);
	return (add);
}
/**
 * show_number - output integer number
 * @ap: argument pointer
 * @user: the argument
 * Return: integer number returned
 */
int show_number(va_list ap, arg_t *user)
{
	long i;

	if (user->last_flag)
		i = va_arg(ap, long);
	else if (user->height_mode)
		i = (short int)va_arg(ap, int);
	else
		i = (int)va_arg(ap, int);
	return (display_numb(converter(i, 10, 0, user), user));
}
/**
 * str_print - output string
 * @ap: argument pointer
 * @user: the argument
 * Return: string returned
 */
int str_print(va_list ap, arg_t *user)
{
	char *string = va_arg(ap, char *), len_str = ' ';
	unsigned int len = 0, add = 0, i = 0, j;
	(void)user;
	switch ((int)(!string))
	case 1:
		string = EMPTY;
		j = len = _strlen(string);
		if (user->precise < len)
			j = len = user->precise;
		if (user->fifth_flag)
		{
			if (user->precise != UINT_MAX)
				for (i = 0; i < len; i++)
					add += _putchar(*string++);
			else
				add += _puts(string);
		}
		while (j++ < user->radius)
			add += _putchar(len_str);
		if (!user->fifth_flag)
		{
			if (user->precise != UINT_MAX)
				for (i = 0; i < len; i++)
					add += _putchar(*string++);
			else
				add += _puts(string);
		}
		return (add);
}
/**
 * percentage - prints string
 * @ap: argument pointer
 * @user: the argument
 * Return: number chars returned
 */
int percentage(va_list ap, arg_t *user)
{
	(void)ap;
	(void)user;
	return (_putchar('%'));
}
/**
 * string_func - format specifier
 * @ap: argument pointer
 * @user: the argument
 * Return: number chars returned
 */
int string_func(va_list ap, arg_t *user)
{
	char *string = va_arg(ap, char *);
	char *ptr;
	int add = 0;

	if ((int)(!string))
		return (_puts(EMPTY));
	for (; *string; string++)
	{
		if ((*string > 0 && *string < 32) || *string >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			ptr = converter(*string, 16, 0, user);
			if (!ptr[1])
				add += _putchar('0');
			add += _puts(ptr);
		}
		else
			add += _putchar(*string);
	}
	return (add);
}
