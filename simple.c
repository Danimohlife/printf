#include "main.h"
/**
 * frint - display char range
 * @begin: beginning range
 * @accept: accept 
 * @end: end
 * Return: byte returned
 */
int frint(char *begin, char *end, char *accept)
{
	int add = 0;
	while (begin <= end)
	{
		if (begin != accept)
			add += _putchar(*begin);
		begin++;
	}
	return (add);
}
/**
 * string_rev - display string in reverse order
 * @ch: input string
 * @user: the struct par
 * Return: bytes returned
 */
int string_rev(va_list ch, arg_t *user)
{
	int fin, add = 0;
	char *string = va_arg(ch, char *);
	(void)user;
	if (string)
	{
		for (fin = 0; *string; string++)
			fin++;
		string--;
		for (; fin > 0; fin--, string--)
			add = add + _putchar(*string);
	}
	return (add);
}
/**
 * string_rot - display string in rot
 * @ch: input string
 * @user: the argument
 * Return: bytes returned
 */
int string_rot(va_list ch, arg_t *user)
{
	int k, index;
	int loop = 0;
	char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *c = va_arg(ch, char *);
	(void)user;
	k = 0;
	index = 0;
	while (c[k])
	{
		if ((c[k] >= 'A' && c[k] <= 'Z') || (c[k] >= 'a' && c[k] <= 'z'))
		{
			index = c[k] - 65;
			loop = loop + _putchar(array[index]);
		}
		else
			loop += _putchar(c[k]);
		k++;
	}
	return (loop);
}
