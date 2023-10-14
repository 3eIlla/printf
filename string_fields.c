#include "main.h"


/*d 2 dol*/
/**
 * get_precision -  precision from strin
 *
 * @p: strin format
 * @params: paramt struct
 * @ap: arg pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int dol = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		dol = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			dol = dol * 10 + (*p++ - '0');
	}
	params->precision = dol;
	return (p);
}
