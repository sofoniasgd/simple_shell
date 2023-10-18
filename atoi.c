#include "shell.h"
/**
 * _atoi - Convert a string to an integer.
 * @str: The string to be converted.
 * Return: The converted integer value.
 */
int _atoi(const char *str)
{
	int result = 0, sign = 1;

	while (*str == ' ' || *str == '\t')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
