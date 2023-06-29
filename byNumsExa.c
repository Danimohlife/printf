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
	static char fubb[BUFF_SIZE];
	static int loop;

	if (ch == BUFF || loop >= BUFF_SIZE)
	{
		write(1, fubb, loop);
		loop = 0;
	}
	if (ch != BUFF)
		fubb[loop++] = ch;
	return (1);
}
/**
 * _puts - output a str along newline
 * @b: the string out vari
 * Return: string
 */
int _puts(char *b)
{
	char *c = b;

	while (*b)
		_putchar(*b++);
	return (b - a);
}
