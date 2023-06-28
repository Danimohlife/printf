/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * display_numb - show me the num
 * @string: string
 * @spacefor: take me to struc
 * Return: chars
 */
int display_numb(char *string, arg_t *spacefor)
{
	unsigned int num = _strlen(string);
	int signum = (!spacefor->unsign && *string == '-');

	if (!spacefor->precise && *string == '0' && !string[1])
		string = "";
	if (signum)
	{
		string++;
		num--;
	}
	if (spacefor->precise != UINT_MAX)
		while (num++ < spacefor->precise)
			*--string = '0';
	if (signum)
		*--string = '-';

	if (!spacefor->fifth_flag)
		return (shift_r_num(string, spacefor));
	else
		return (shift_l_num(string, spacefor));
}
/**
 * shift_r_num - number ops
 * @string: number string
 * @spacefor: struct
 * Return: printed
 */
int shift_r_num(char *string, arg_t *spacefor)
{
	char spac = ' ';
	unsigned int num = 0, minus, nex, lop = _strlen(string);

	if (spacefor->flag && !spacefor->fifth_flag)
		spac = '0';
	minus = nex = (!spacefor->unsign && *string == '-');
	if (minus && lop < spacefor->radius && spac == '0' && !spacefor->fifth_flag)
		string++;
	else
		minus = 0;
	if ((spacefor->added && !nex) ||
		(!spacefor->added && spacefor->space && !nex))
		lop++;
	if (minus && spac == '0')
		num += _putchar('-');
	if (spacefor->added && !nex && spac == '0' && !spacefor->unsign)
		num += _putchar('+');
	else if (!spacefor->added && spacefor->space && !nex &&
		!spacefor->unsign && spacefor->flag)
		num += _putchar(' ');
	while (lop++ < spacefor->radius)
		num += _putchar(spac);
	if (minus && spac == ' ')
		num += _putchar('-');
	if (spacefor->added && !nex && spac == ' ' && !spacefor->unsign)
		num += _putchar('+');
	else if (!spacefor->added && spacefor->space && !nex &&
		!spacefor->unsign && !spacefor->flag)
		num += _putchar(' ');
	num += _puts(str);
	return (num);
}

/**
 * shift_l_num - l for r
 * @string: for string
 * @user: struc para
 * Return: char
 */
int shift_l_num(char *string, arg_t *user)
{
	unsigned int num = 0, minus, nex, lop = _strlen(string);
	char spac = ' ';

	if (user->flag && !user->fifth_flag)
		spac = '0';
	minus = nex = (!user->unsign && *string == '-');
	if (minus && lop < user->radius && pad_char == '0' && !user->fifth_flag)
		string++;
	else
		minus = 0;

	if (user->added && !nex && !user->unsign)
		num += _putchar('+'), lop++;
	else if (user->space && !nex && !user->unsign)
		num += _putchar(' '), lop++;
	num += _puts(string);
	while (lop++ < user->radius)
		num += _putchar(spac);
	return (num);
}
