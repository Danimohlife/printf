#include "main.h"
/**
 * _printf - fake printf
 * @format: base on specification
 * Return: bytes returned
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char *c, *d;
	int add = 0;

	arg_t user = PRINT_STARTER;

	va_start(ap, format);

	if ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	if ((format[0] == '%' && format[1]) == (' ' && !format[2]))
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		callstruct(&user, ap);
		if (*c != '%')
		{
			add += _putchar(*c);
			continue;
		}
		d = c;
		c++;
		while (print_fg(c, &user))
			c++;
		c = radius_func(c, &user, ap);
		c = specifier_collec(c, &user, ap);
		if (modify_func(c, &user))
			c++;
		if (!func_ptr(c))
			add += frint(d, c,
user.last_flag || user.height_mode ? c - 1 : 0);
		else
			add += find_func(c, ap, &user);
	}
	_putchar(BUFF);
	va_end(ap);
	return (add);
}
