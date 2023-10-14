#ifndef _PRINTF_H
#define _PRINTF_H

#include<stdio.h>
#include<limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 *struct parameters - parameters struct
 *
 *@unsign: for unsigned value
 *
 * @plus_flag: for plus_flag specified
 * @space_flag: forhashtag_flag specified
 * @hashtag_flag: for if _flag specified
 * @zero_flag: for _flag specified
 * @minus_flag: for _flag specified
 *
 * @width:  width
 * @precision:  precision
 *
 *@h_modifier: for h_modifier
 *@l_modifier: l_modifier
 *
 */
typedef struct parameters
{

	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 *struct specifier - Struct token
 *
 *@specifier: token
 *@f: actual function
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _prinf.c function */
int _printf(const char *format, ...);

/* puts.c function */
int _puts(char *str);
int _putchar(int c);

/* paramaters.c function */
void init_params(params_t *params, va_list ap);

/* string_fields.c function */
char *get_precision(char *p, params_t *params, va_list ap);

/* 1-printing_fun.c function */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);

/* 2-printing_fun.c function*/
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* hex_lowe_upperr.c function */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);

/* binary.c function*/
int print_binary(va_list ap, params_t *params);

/*octal.c function*/
int print_octal(va_list ap, params_t *params);

/* numbers.c function */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* the_specifier.c function */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* 1-printing_nums.c function */
int _isdigit(int c);
int _strlen(char *s);

/*2-printing_nums.c function*/
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* rot13.c function */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

#endif
