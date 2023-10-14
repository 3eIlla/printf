#ifndef _PRINTF_H
#define _PRINTF_H

/*Libraries*/
#include <stdio.h>    /*For any out in puts */

#include <unistd.h>  /*for display the function write */

#include <stdarg.h>   /*for  */

#include <stdarg.h>   /*for argument after "..."*/

#include <limits.h>   /*for max byet no. */

#include <stdlib.h>


/* for task 4 */
/* macro & malloc Size of memo */

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


/* for task 3 : 7 */
#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign:  unsigned value flag
 *
 * @plus_flag: flag to % +
 * @space_flag: flag to % ' '
 * @hashtag_flag: flag to % #
 *
 * @minus_flag: flag to % -
 *
 * @l_modifier: % l_modifier 
 * @h_modifier: % h_modifier 
 *
 * @width: field width specified
 *
 * @precision: field precision specified
 *
 * @zero_flag: flag to % 0
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	
	unsigned int minus_flag		: 1;

	unsigned int l_modifier		: 1;
	unsigned int h_modifier		: 1;

	unsigned int width;

	unsigned int precision;

	unsigned int zero_flag		: 1;

} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: func associated
 *
 */
typedef struct specifier
{

	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* File: alx_puts.c  */
int _putchar(int c);
int _puts(char *str);


/* File: the_params.c */
void init_params(params_t *params, va_list ap);

/* File: string_fields.c  */
char *get_precision(char *p, params_t *params, va_list ap);

/* File: _prinf.c  */
int _printf(const char *format, ...);



/* File: the_print_funcs.c  */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* File: the_no.c  */
char *convert(long int num, int base, int flags, params_t *params);
int print_address(va_list ap, params_t *params);

/* File: the_specifier.c */
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
/*task 8*/
int get_modifier(char *s, params_t *params);


/* File: specifier_point.c */
int (*get_specifier(char *s))(va_list ap, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);


/* File: the_converter.c  */

int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* File: the_printers.c  */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* File: the_length.c */
int _isdigit(int c);
int _strlen(char *s);

/* File: the_nums.c */
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);


#endif
