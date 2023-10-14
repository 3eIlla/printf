#include "main.h"

// ptr + array + sign
/**
 * convert - converter funcss 2  clone o itoa
 *
 * @num: no
 * @base: base
 * @flags: argums flags
 * @paras: params struct
 *
 * Return: strin
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	char *ptr;
	char sign = 0;

	static char *array;
	static char buffer[50];

	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}


// n
/**
 * print_address - address
 *
 * @ap: argums pointr
 * @params: params struct
 *
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *params)
{
	char *str;
	unsigned long int n = va_arg(ap, unsigned long int);
	

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
