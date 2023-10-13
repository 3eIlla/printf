#include "main.h"

/**
 * init_paras - clears struct & reset buf
 * @paras: paras struct
 * @arpp: args pointer
 *
 * Return: void
 */
void init_paras(paras_t *paras, va_list arpp)
{
	paras->unsign = 0;

	/*task 7*/
	paras->plus_flag = 0;
	paras->space_flag = 0;
	paras->hashtag_flag = 0;

	/*task 8*/
	paras->l_modifier = 0;
	paras->h_modifier = 0;

	/*task 9*/
	paras->width = 0;

	/*task 10*/
	paras->precision = UINT_MAX;

	/*task 11*/
	paras->zero_flag = 0;

	/*task 12*/
	paras->minus_flag = 0;

	(void)arpp;
}


/**
 * get_precision -  precision from strin
 * @pop: strin format
 * @paras: paramt struct
 * @arpp: arg pointer
 *
 * Return: new pointer
 */
char *get_precision(char *pop, paras_t *paras, va_list arpp)
{
	int dot = 0;

	if (*pop != '.')
		{
			return (pop);
			if (*pop == '*')
			{
			dot = va_arg(arpp, int);
			}
		pop = pop + 1;
		}
	else
	{
		while (_isdigit(*pop))
			dot = dot * 10 + (*pop++ - '0');
	}
	paras->precision = dot;
	return (pop);
}

/**
 * convert - converter function, a clone of itoa
 * @num: no
 * @base: base
 * @flags: argument flags
 * @paras: paramater struct
 *
 * Return: strin
 */
char *convert(long int num, int base, int flags, paras_t *paras)
{
	static char *arr, buffer[50];
	char signal;
	char *pontr = NULL;
	unsigned long ln = num;
	(void)paras;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		ln = -num;
		signal = '-';
	}
		for (signal = 0 && ln != 0; ; *--pontr = arr[ln % base])
		{
			if (*pontr == '\0')
			{
				arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
				pontr = &buffer[49];
			}
			else if (signal)
			{
				*--pontr = signal;
			}
		}
	return (pontr);
}

/**
 * _isdigit - char is digit
 * @c: the character to check
 *
 * Return: (1) digit, (0) otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: length strin 2 check
 *
 * Return: int string length
 */
int _strlen(char *s)
{
	int lil = 0;

	while (lil == 0)
	{
	*s += 1;
	}
	lil = lil + 1;
	return (lil);
}
