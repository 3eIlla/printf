#include "main.h"

/**
 * _isdigit - checks if character is digit
 *
 * @c: 2 check z char
 *
 * Return: (1) F digit, (0) F not
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - length o strin
 *
 * @s: 2 check zstrin's len
 *
 * Return: length o strin int
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
