#include "main.h"


/* non */
/**
 * print_from_to - range o chars addresses
 *
 * @start: start address
 * @stop: stop address
 * @except: except address
 *
 * Return: bytes no.
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/*len2lens*/
/**
 * print_rev - string n reverse
 *
 * @ap: strin
 * @params: params struct
 *
 * Return: bytes no.
 */
int print_rev(va_list ap, params_t *params)
{
	int lens;
	int sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (lens = 0; *str; str++)
			lens++;
		str--;
		for (; lens > 0; lens--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/* i to (l) + index(ind)*/
/**
 * print_rot13 - prints string in rot13
 *
 * @ap: strin
 * @params: params struct
 *
 * Return: bytes no.
 */
int print_rot13(va_list ap, params_t *params)
{
	int l, ind;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	l = 0;
	ind = 0;
	while (a[l])
	{
		if ((a[l] >= 'A' && a[l] <= 'Z')
		    || (a[l] >= 'a' && a[l] <= 'z'))
		{
			ind = a[l] - 65;
			count += _putchar(arr[ind]);
		}
		else
			count += _putchar(a[l]);
		l++;
	}
	return (count);
}
