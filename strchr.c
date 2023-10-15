#include "shell.h"
/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @str: The input string to search.
 * @c: The character to search for.
 * Return: A pointer to the first occurrence of 'c' in 'str',
 *			or NULL if 'c' is not found.
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
