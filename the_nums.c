#include "main.h"

/*i2x*/
/**
 * print_number - no. with options
 *
 * @str: strin o base no.
 * @params: params struct
 *
 * Return: chars
 */
int print_number(char *str, params_t *params)
{
	unsigned int x = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		x--;
	}
	if (params->precision != UINT_MAX)
		while (x++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/*i2x + n2h*/
/**
 * print_number_right_shift - no. with options
 *
 * @str: strin o base no.
 * @params: params struct
 *
 * Return: chars
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int h = 0, neg, neg2;
	unsigned int x = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && h < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		x++;
	if (neg && pad_char == '0')
		h += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		h += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		h += _putchar(' ');
	while (x++ < params->width)
		h += _putchar(pad_char);
	if (neg && pad_char == ' ')
		h += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		h += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		h += _putchar(' ');
	h += _puts(str);
	return (h);
}

/*neg 1 + neg 2  (same :: up & dowm)*/


/*i2u + n2m*/
/**
 * print_number_left_shift - no. with options
 *
 * @str: strin o base no.
 * @params: params struct
 *
 * Return: chars
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int m = 0, neg, neg2;
	unsigned int u = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && u < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		m += _putchar('+'), u++;
	else if (params->space_flag && !neg2 && !params->unsign)
		m += _putchar(' '), u++;
	m += _puts(str);
	while (u++ < params->width)
		m += _putchar(pad_char);
	return (m);
}
