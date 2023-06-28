#include "main.h"
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
