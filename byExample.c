#include "main.h"
/**
 * converter - regular function
 * @b: for numb display
 * @f: for base
 * @a: argument flags
 * Return: string
 */
char *converter(long int a, int b, int f)
{
	static char *of_arr, base[50];
	char str_si = 0, *pstd;
	unsigned long num;

	num = a;

	if (!(f & UNSIGNED_CON) && a < 0)
	{
		num = -a;
		str_si = '-';
	}
	of_arr = f & LOWERCASE_CON ? "0123456789abcdef" : "0123456789ABCDEF";
	pstd = &base[49];
	*pstd = '\0';

	do	{
		*--pstd = of_arr[num % b];
		num /= b;
	} while (num != 0);

	if (str_si)
		*--pstd = str_si;
	return (pstd);
}
/**
 * unsigned_num - unsigned numbers
 * @p: pointer
 * @op: the par
 * Return: prd
 */
int unsigned_num(va_list p, arg_t *op)
{
	unsigned long nlp;

	if (op->last_flag)
		nlp = (unsigned long)va_arg(p, unsigned long);
	else if (op->height_mode)
		nlp = (unsigned short int)va_arg(p, unsigned int);
	else
		nlp = (unsigned int)va_arg(p, unsigned int);
	op->unsign = 1;

	return (display_numb(converter(nlp, 10, UNSIGNED_CON, op), *op));
}
/**
 * _address_of - an address
 * @p: always
 * @pr: the struct
 * Return: byte
 */
int _address_of(va_list p, arg_t *pr)
{
	unsigned long int i = va_arg(p, unsigned long int);
	char *string;

	if (!i)
		return (_puts("(nil)"));

	string = converter(i, 16, UNSIGNED_CON | LOWERCASE_CON, pr);
	*--string = 'x';
	*--string = '0';
	return (display_numb(string, pr));
}
/**
 * specifier_collec - bring de format
 * @p: form1
 * @ch: form2
 * @user: ptr to stru
 * Return: ptr
*/
char *specifier_collec(char *ch, arg_t *user, va_list p)
{
	int num = 0;

	if (*ch != '.')
		return (ch);
	ch++;
	if (*ch == '*')
	{
		num = va_arg(p, int);
		ch++;
	}
	else
	{
		while (_isdigit(*ch))
			num = num * 10 + (*ch++ - '0');
	}
	user->precise = num;
	return (ch);
}
