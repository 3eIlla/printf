#include "main.h"

/**
 * _printf - print func
 * @format: format strin
 *
 * Return: bytes no.
 */
int _printf(const char *format, ...)
{
	int csumi = 0;
	va_list arpp;
	char *pop, *sttr;
	paras_t paras = PARAS_INIT;

	va_start(arpp, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	else if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (pop = (char *)format; *pop; pop++)
	{
		for (init_paras(&paras, arpp); !get_specifier(pop); pop++)
		{
		for (sttr = pop; *pop != '%'; pop++)
		{
			csumi += _putchar(*pop);
			continue;
		}
		do

		{
			pop = get_width(pop, &paras, arpp);
			pop = get_precision(pop, &paras, arpp);
		} while (get_flag(pop, &paras));
		pop = pop + 1;
				csumi += print_from_to(sttr, pop,
				paras.l_modifier || paras.h_modifier ? pop - 1 : 0);
	}
	csumi += get_print_func(pop, arpp, &paras);
	}
_putchar(BUF_FLUSH);
va_end(arpp);
return (csumi);
}
