#include "main.h"

/*none*/
/**
 * print_char - chars
 *
 * @ap: args pointer
 * @params: params struct
 *
 * Return: chars no.
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int ch = va_arg(ap, int);
	unsigned int pad = 1, sum = 0;

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/*l2s*/
/**
 * print_int - ints
 *
 * @ap: args pointer
 * @params: params struct
 *
 * Return: chars no.
 */
int print_int(va_list ap, params_t *params)
{
	long s;

	if (params->l_modifier)
		s = va_arg(ap, long);
	else if (params->h_modifier)
		s = (short int)va_arg(ap, int);
	else
		s = (int)va_arg(ap, int);
	return (print_number(convert(s, 10, 0, params), params));
}

/*i2l + j2k*/
/**
 * print_string - strin
 *
 * @ap: args pointer
 * @params: params struct
 *
 * Return: chars no.
 */
int print_string(va_list ap, params_t *params)
{
	unsigned int l = 0, k;
		unsigned int pad = 0, sum = 0;
		char *str = va_arg(ap, char *), pad_char = ' ';


	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	k = pad = _strlen(str);
	if (params->precision < pad)
		k = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (l = 0; l < pad; l++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (k++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (l = 0; l < pad; l++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/*none*/
/**
 * print_S -  specifier's custom form
 *
 * @ap: args pointer
 * @params: params struct
 *
 * Return: chars no.
 */
int print_S(va_list ap, params_t *params)
{
	int sum = 0;
	char *str = va_arg(ap, char *);
	char *hex;


	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
