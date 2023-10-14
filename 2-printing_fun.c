#include "main.h"

/**
 *print_percent - prints the string
 *@ap: pointer
 *@params: struct
 *Return:  chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;

	return (_putchar('%'));
}

/**
 *print_S - format specifier
 *@ap: pointer
 *@params: struct
 *Return: chars printed
 */
int print_S(va_list ap, params_t *params)
{

	char *str = va_arg(ap, char *);

	char *hex;

	int sum = 0;

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
