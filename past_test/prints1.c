#include "main.h"

/**
 * print_char - prints character
 * @arpp: argument pointer
 * @paras: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list arpp, paras_t *paras)
{
	char pad_char = ' ';
	unsigned int pad = 1, csumi = 0, ch = va_arg(arpp, int);

	if (paras->minus_flag)
		csumi += _putchar(ch);
	while (pad++ < paras->width)
		csumi += _putchar(pad_char);
	if (!paras->minus_flag)
		csumi += _putchar(ch);
	return (csumi);
}

/**
 * print_int - prints integer
 * @arpp: argument pointer
 * @paras: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list arpp, paras_t *paras)
{
	long ln;

	if (paras->l_modifier)
		ln = va_arg(arpp, long);
	else if (paras->h_modifier)
		ln = (short int)va_arg(arpp, int);
	else
		ln = (int)va_arg(arpp, int);
	return (print_number(convert(ln, 10, 0, paras), paras));
}

/**
 * print_string - prints string
 * @arpp: argument pointer
 * @paras: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list arpp, paras_t *paras)
{
	char *str = va_arg(arpp, char *), pad_char = ' ';
	unsigned int pad = 0, csumi = 0, lil = 0, j;

	(void)paras;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (paras->precision < pad)
		j = pad = paras->precision;

	if (paras->minus_flag)
	{
		if (paras->precision != UINT_MAX)
			for (lil = 0; lil < pad; lil++)
				csumi += _putchar(*str++);
		else
			csumi += _puts(str);
	}
	while (j++ < paras->width)
		csumi += _putchar(pad_char);
	if (!paras->minus_flag)
	{
		if (paras->precision != UINT_MAX)
			for (lil = 0; lil < pad; lil++)
				csumi += _putchar(*str++);
		else
			csumi += _puts(str);
	}
	return (csumi);
}

/**
 * print_percent - prints string
 * @arpp: argument pointer
 * @paras: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list arpp, paras_t *paras)
{
	(void)arpp;
	(void)paras;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @arpp: argument pointer
 * @paras: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list arpp, paras_t *paras)
{
	char *str = va_arg(arpp, char *);
	char *hex;
	int csumi = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			csumi += _putchar('\\');
			csumi += _putchar('x');
			hex = convert(*str, 16, 0, paras);
			if (!hex[1])
				csumi += _putchar('0');
			csumi += _puts(hex);
		}
		else
		{
			csumi += _putchar(*str);
		}
	}
	return (csumi);
}
