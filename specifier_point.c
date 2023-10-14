#include "main.h"

// i
/**
 * get_specifier - finds z formats funcs
 *
 * @s: strin o format
 *
 * Return: bytes no.
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
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

	int i = 0;
	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}


// d
/**
 * get_width - width from strin
 *
 * @s: format strin
 * @params: parames struct
 * @ap: args pointer
 *
 * Return: N.pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
