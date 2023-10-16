#include "shell.h"

/**
 * _strncpy - copies one string into another
 * @dest: destination string
 * @src: source string
 * @n: max number of bytes to copy
 * Return: pointer to destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && *(src + i) != '\0'; i++)
	{
	*(dest + i) = *(src + i);
	}
*(dest + n) = '\0';
return (dest);
}
