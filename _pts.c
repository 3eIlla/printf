#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int lil;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || lil >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, lil);
		lil = 0;
	}
	if (c != BUF_FLUSH)
		buf[lil = lil + 1] = c;
	return (1);
}
