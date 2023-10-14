#include "main.h"


/*none*/
/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/*i2y*/
/**
 * get_flag - finds the flag func
 *
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int y = 0;

	switch (*s)
	{
		case '+':
			y = params->plus_flag = 1;
			break;
		case ' ':
			y = params->space_flag = 1;
			break;
		case '#':
			y = params->hashtag_flag = 1;
			break;
		case '-':
			y = params->minus_flag = 1;
			break;
		case '0':
			y = params->zero_flag = 1;
			break;
	}
	return (y);
}

/*i2y*/
/**
 * get_modifier - modifier func
 *
 * @s: string format
 * @params: parames struct
 *
 * Return: modifier valid
 */
int get_modifier(char *s, params_t *params)
{
	int y = 0;

	switch (*s)
	{
	case 'h':
		y = params->h_modifier = 1;
		break;
	case 'l':
		y = params->l_modifier = 1;
		break;
	}
	return (y);
}
