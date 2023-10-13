#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @sttr: starting address
 * @sttp: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *sttr, char *sttp, char *except)
{
	int csumi = 0;

	while (sttr <= sttp)
	{
		if (sttr != except)
			csumi += _putchar(*sttr);
		sttr++;
	}
	return (csumi);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @paras: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, paras_t *paras)
{
	unsigned int lil = _strlen(str);
	int neg = (!paras->unsign && *str == '-');

	if (!paras->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		lil--;
	}
	if (paras->precision != UINT_MAX)
		while (lil++ < paras->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!paras->minus_flag)
		return (print_number_right_shift(str, paras));
	else
		return (print_number_left_shift(str, paras));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @paras: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, paras_t *paras)
{
	unsigned int ln = 0, neg, neg2, lil = _strlen(str);
	char pad_char = ' ';

	if (paras->zero_flag && !paras->minus_flag)
		pad_char = '0';
	neg = neg2 = (!paras->unsign && *str == '-');
	if (neg && lil < paras->width && pad_char == '0' && !paras->minus_flag)
		str++;
	else
		neg = 0;
	if ((paras->plus_flag && !neg2) ||
		(!paras->plus_flag && paras->space_flag && !neg2))
		lil++;
	if (neg && pad_char == '0')
		ln += _putchar('-');
	if (paras->plus_flag && !neg2 && pad_char == '0' && !paras->unsign)
		ln += _putchar('+');
	else if (!paras->plus_flag && paras->space_flag && !neg2 &&
		!paras->unsign && paras->zero_flag)
		ln += _putchar(' ');
	while (lil++ < paras->width)
		ln += _putchar(pad_char);
	if (neg && pad_char == ' ')
		ln += _putchar('-');
	if (paras->plus_flag && !neg2 && pad_char == ' ' && !paras->unsign)
		ln += _putchar('+');
	else if (!paras->plus_flag && paras->space_flag && !neg2 &&
		!paras->unsign && !paras->zero_flag)
		ln += _putchar(' ');
	ln += _puts(str);
	return (ln);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @paras: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, paras_t *paras)
{
	unsigned int ln = 0, neg, neg2, lil = _strlen(str);
	char pad_char = ' ';

	if (paras->zero_flag && !paras->minus_flag)
		pad_char = '0';
	neg = neg2 = (!paras->unsign && *str == '-');
	if (neg && lil < paras->width && pad_char == '0' && !paras->minus_flag)
		str++;
	else
		neg = 0;

	if (paras->plus_flag && !neg2 && !paras->unsign)
		ln += _putchar('+'), lil++;
	else if (paras->space_flag && !neg2 && !paras->unsign)
		ln += _putchar(' '), lil++;
	ln += _puts(str);
	while (lil++ < paras->width)
		ln += _putchar(pad_char);
	return (ln);
}
