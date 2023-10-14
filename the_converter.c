#include "main.h"

/*l 2 lol*/
/**
 * print_unsigned - unsigned integer no.
 *
 * @ap: argums pointr
 * @params: params struct
 *
 * Return: bytes
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long lol;

	if (params->l_modifier)
		lol = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lol = (unsigned short int)va_arg(ap, unsigned int);
	else
		lol = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(lol, 10, CONVERT_UNSIGNED, params), params));
}


/**
 * print_hex - unsigned hex no. n lowercase
 *
 * @ap: z args pointer
 * @params: z prams struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long lol;
	int c = 0;
	char *str;

	if (params->l_modifier)
		lol = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lol = (unsigned short int)va_arg(ap, unsigned int);
	else
		lol = (unsigned int)va_arg(ap, unsigned int);

	str = convert(lol, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && lol)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/* l 2 lol + c . (same :: up & down) */


/**
 * print_HEX - unsigned hex no. n uppercase
 *
 * @ap: z args pointer
 * @params: z prams struct
 *
 * Return: bytes
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long lol;
	int c = 0;
	char *str;

	if (params->l_modifier)
		lol = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lol = (unsigned short int)va_arg(ap, unsigned int);
	else
		lol = (unsigned int)va_arg(ap, unsigned int);

	str = convert(lol, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && lol)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}


/* c 2 cc + n*/
/**
 * print_binary - unsigned binary no.
 *
 * @ap: z args pointer
 * @params: z prams struct
 *
 * Return: bytes
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int cc = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (cc += print_number(str, params));
}

/* c 2 cc + l 2 lol */
/**
 * print_octal - unsigned octal no.
 *
 * @ap: z args pointer
 * @params: z prams struct
 *
 * Return: bytes
 */
int print_octal(va_list ap, params_t *params)
{
	int cc = 0;
	char *str;
	unsigned long lol;

	if (params->l_modifier)
		lol = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lol = (unsigned short int)va_arg(ap, unsigned int);
	else
		lol = (unsigned int)va_arg(ap, unsigned int);
	str = convert(lol, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && lol)
		*--str = '0';
	params->unsign = 1;
	return (cc += print_number(str, params));
}
