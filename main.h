#ifndef MAIN_H
#define MAIN_H

/*Libraries*/
#include <stdio.h>    /*For any out in puts */

#include <unistd.h>  /*for display the function write */

#include <stdarg.h>   /*for  */

#include <stdarg.h>   /*for argument after "..."*/

#include <limits.h>   /*for max byet no. */

#include <stdlib.h>

/* task 4*/
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"


/* for task 3 : 7 */
#define PARAS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

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

} paras_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*func)(va_list, paras_t *);
} specifier_t;



/* _pts.c */
int _puts(char *str);
int _putchar(int c);

/* _prinf.c */
int _printf(const char *format, ...);


/* .    helper.c .  */
/* parameters  */
void init_paras(paras_t *paras, va_list arpp);
/* strings fields  */
char *get_precision(char *pop, paras_t *paras, va_list arpp);
/* number converter */
char *convert(long int num, int base, int flags, paras_t *paras);
/* print numbers  */
int _isdigit(int c);
int _strlen(char *s);


/*  _gets.c .    TO GET ANYTHING     */
/* get specifieres */
int (*get_specifier(char *s))(va_list arpp, paras_t *paras);
int get_print_func(char *s, va_list arpp, paras_t *paras);
int get_flag(char *s, paras_t *paras);
int get_modifier(char *s, paras_t *paras);
char *get_width(char *s, paras_t *paras, va_list arpp);






/* prints.c .   TO PRINT EVERYTHING     */

/*p 1*/
/* print functions  */
int print_char(va_list arpp, paras_t *paras);
int print_int(va_list arpp, paras_t *paras);
int print_string(va_list arpp, paras_t *paras);
int print_percent(va_list arpp, paras_t *paras);
int print_S(va_list arpp, paras_t *paras);


/*p 2*/
/* print no. that need convert */
/*t1*/
int print_binary(va_list arpp, paras_t *paras);
/*t3*/
int print_octal(va_list arpp, paras_t *paras);
int print_hex(va_list arpp, paras_t *paras);
int print_HEX(va_list arpp, paras_t *paras);



/*p 3*/
/* simple printers no. */
int print_from_to(char *sttr, char *sttp, char *except);
/* print number */
int print_number(char *str, paras_t *paras);
int print_number_right_shift(char *str, paras_t *paras);
int print_number_left_shift(char *str, paras_t *paras);


/*p 4*/
/* print about number */
int print_address(va_list arpp, paras_t *paras);
int print_unsigned(va_list arpp, paras_t *paras);
/* simple printers no. */
int print_rev(va_list arpp, paras_t *paras);
int print_rot13(va_list arpp, paras_t *paras);


#endif
