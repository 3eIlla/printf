#include "main.h"
/*edit done*/
/*ptr 2ptrs + array 2 grray + sign 2 gsign*/
/**
 * convert - converter funcss 2  clone o itoa
 *
 * @num: no
 * @base: base
 * @flags: argums flags
 * @params: params struct
 *
 * Return: strin
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	char *ptrs;
	char gsign = 0;

	static char *grray;
	static char buffer[50];

	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		gsign = '-';

	}
	grray = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptrs = &buffer[49];
	*ptrs = '\0';

	do	{
		*--ptrs = grray[n % base];
		n /= base;
	} while (n != 0);

	if (gsign)
		*--ptrs = gsign;
	return (ptrs);
}


/* n 2 x */
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
	unsigned long int x = va_arg(ap, unsigned long int);


	if (!x)
		return (_puts("(nil)"));

	str = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
