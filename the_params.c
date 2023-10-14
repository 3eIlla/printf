#include "main.h"


/*none*/
/**
 * print_percent - strin
 *
* @ap: args pointer
 * @params: params struct
 *
 * Return: chars no.
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}


/*none*/
/**
 * init_params - clears struct & reset buf
 *
 * @ap: args pointer
 * @params: params struct
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;

	params->minus_flag = 0;

	params->h_modifier = 0;
	params->l_modifier = 0;

	params->width = 0;

	params->precision = UINT_MAX;

	params->zero_flag = 0;

	(void)ap;
}
