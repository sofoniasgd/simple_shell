#include "shell.h"
/**
 * _strcpy - function that copy from source to distination
 * @destination: copy to
 * @source: copy from
 * Return: a pointer to start of destination string
 */
char *_strcpy(char *destination, const char *source)
{
	char *start = destination;

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (start);
}
/**
 * _strcmp - Compare two strings lexicographically.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * Return: 0 if the strings are equal, a negative value
 *	if str1 is less than str2,
 *	or a positive value if str1 is greater than str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	else if (*str1 == '\0')
		return (-1);
	else
		return (1);
}
/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string, where the result will be stored.
 * @src: The source string to be appended to the destination.
 * Return: A pointer to the destination string (dest).
 */
char *_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
/**
 * _strdup - Duplicate a string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string,
 *			or NULL if memory allocation fails.
 */
char *_strdup(const char *str)
{
	size_t length = strlen(str);
	char *duplicate = (char *)malloc(length + 1);

	if (duplicate == NULL)
		return (NULL);
	_strcpy(duplicate, str);
	return (duplicate);
}
