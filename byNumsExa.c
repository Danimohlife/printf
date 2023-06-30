#include "main.h"
/**
 * callstruct - struct fields & reset
 * @struc: the struct
 * Return: void
 */
void callstruct(arg_t *struc)

{
	struc->unsign = 0;
	struc->added = 0;
	struc->space = 0;
	struc->third_flag = 0;
	struc->flag = 0;
	struc->fifth_flag = 0;
	struc->radius = 0;
	struc->precise = UINT_MAX;
	struc->height_mode = 0;
	struc->last_flag = 0;
}
/**
 * _putchar - writes the character c to stdout
 * @ch: The character to print
 * Return: return unsigned int if success
 */
int _putchar(int ch)
{
	return (write(1, &ch, 1));
}
/**
 * _puts - output a str along newline
 * @b: the string out vari
 * Return: string
 */
void _puts(char *b)
{

	while (*b != '\0')
		_putchar(*b++);
	_putchar('\');
}
