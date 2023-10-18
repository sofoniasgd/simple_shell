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
int i = 0, len = n;

for (i = 0; i < len && *(src + i) != '\0'; i++)
	{
	*(dest + i) = *(src + i);
	}
while (i < len)
{
	*(dest + len) = '\0';
	i++;
}
return (dest);
}
