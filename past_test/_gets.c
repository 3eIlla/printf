#include "main.h"

/**
 * get_specifier - func format
 * @s: string format
 *
 * Return: bytes no.
 */
int (*get_specifier(char *s))(va_list arpp, paras_t *paras)
{
	specifier_t specifiers[] = {
/*0*/
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
/*1*/
		{"d", print_int},
		{"i", print_int},
/*1*/
		{"b", print_binary},
/*3*/
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
/*5*/
		{"S", print_S},
/*6*/
		{"p", print_address},
/*13*/
		{"r", print_rev},
/*14*/
		{"R", print_rot13},
		{NULL, NULL}
	};

	int lil;
	for (lil = 0; specifiers[lil].specifier; lil++)
	{
		if (*s == specifiers[lil].specifier[0])
		{
			return (specifiers[lil].func);
		}
	}
	return (0);
}

/**
 * get_print_func - func format
 * @s: string format
 * @arpp: arg pointr
 * @paras: parames struct
 *
 * Return: bytes no.
 */
int get_print_func(char *s, va_list arpp, paras_t *paras)
{
	int (*func)(va_list, paras_t *) = get_specifier(s);

	if (func)
	{
		return (func(arpp, paras));
	}
	return (0);
}

/**
 * get_flag - func flag
 * @s: strin format
 * @paras: parames struct
 *
 * Return: flag valid
 */
int get_flag(char *s, paras_t *paras)
{
	int lil = 0;

	switch (*s)
	{
/*7*/
		case '+':
			lil = paras->plus_flag = 1;
			break;
		case ' ':
			lil = paras->space_flag = 1;
			break;
		case '#':
			lil = paras->hashtag_flag = 1;
			break;
/*11*/
		case '0':
			lil = paras->zero_flag = 1;
			break;
/*12*/
		case '-':
			lil = paras->minus_flag = 1;
			break;
	}
	return (lil);
}

/**
 * get_modifier - modifier func
 * @s: string format
 * @paras: parames struct
 *
 * Return: modifier valid
 */
int get_modifier(char *s, paras_t *paras)
{
	int lil = 0;

	switch (*s)
	{
/*8*/
	case 'h':
		lil = paras->h_modifier = 1;
		break;
	case 'l':
		lil = paras->l_modifier = 1;
		break;
	}
	return (lil);
}

/**
 * get_width - width from strin
 * @s: format strin
 * @paras: parames struct
 * @arpp: arg pointer
 *
 * Return: N.pointer
 */
char *get_width(char *s, paras_t *paras, va_list arpp)
{
	int dot = 0;

	if (*s == '*')
	{
		dot = va_arg(arpp, int);
		s = s + 1;
	}
	for (dot = 0; _isdigit(*s); paras->width = dot)
	{
		dot = dot * 10 + (*s++ - '0');
	}
	return (s);
}
