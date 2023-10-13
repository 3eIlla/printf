#include "main.h"

/**
 * print_binary - prints unsigned binary number
 * @arpp: the argument pointer
 * @paras: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list arpp, paras_t *paras)
{
	unsigned int ln = va_arg(arpp, unsigned int);
	char *str = convert(ln, 2, CONVERT_UNSIGNED, paras);
	int c = 0;

	if (paras->hashtag_flag && ln)
		*--str = '0';
	paras->unsign = 1;
	return (c += print_number(str, paras));
}

/**
 * print_octal - prints unsigned octal numbers
 * @arpp: the argument pointer
 * @paras: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list arpp, paras_t *paras)
{
	unsigned long ln;
	char *str;
	int c = 0;

	if (paras->l_modifier)
		ln = (unsigned long)va_arg(arpp, unsigned long);
	else if (paras->h_modifier)
		ln = (unsigned short int)va_arg(arpp, unsigned int);
	else
		ln = (unsigned int)va_arg(arpp, unsigned int);
	str = convert(ln, 8, CONVERT_UNSIGNED, paras);

	if (paras->hashtag_flag && ln)
		*--str = '0';
	paras->unsign = 1;
	return (c += print_number(str, paras));
}

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @arpp: the argument pointer
 * @paras: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list arpp, paras_t *paras)
{
	unsigned long ln;
	int c = 0;
	char *str;

	if (paras->l_modifier)
		ln = (unsigned long)va_arg(arpp, unsigned long);
	else if (paras->h_modifier)
		ln = (unsigned short int)va_arg(arpp, unsigned int);
	else
		ln = (unsigned int)va_arg(arpp, unsigned int);

	str = convert(ln, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, paras);
	if (paras->hashtag_flag && ln)
	{
		*--str = 'x';
		*--str = '0';
	}
	paras->unsign = 1;
	return (c += print_number(str, paras));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @arpp: the argument pointer
 * @paras: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list arpp, paras_t *paras)
{
	unsigned long ln;
	int c = 0;
	char *str;

	if (paras->l_modifier)
		ln = (unsigned long)va_arg(arpp, unsigned long);
	else if (paras->h_modifier)
		ln = (unsigned short int)va_arg(arpp, unsigned int);
	else
		ln = (unsigned int)va_arg(arpp, unsigned int);

	str = convert(ln, 16, CONVERT_UNSIGNED, paras);
	if (paras->hashtag_flag && ln)
	{
		*--str = 'X';
		*--str = '0';
	}
	paras->unsign = 1;
	return (c += print_number(str, paras));
}
