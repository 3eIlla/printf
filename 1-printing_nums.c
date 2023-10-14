#include "main.h"

/**
 * _isdigit - checks if character is a digit
 * @c: the character to be checked
 * Return: (1) if digit, (0) else
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - length of a string
 * @s: the string whose length to be  checked
 * Return: int length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
