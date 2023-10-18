#include "shell.h"
/**
 * remdelimiter - removes delimiter bytes to the front of a string
 * @strc: buffer pointer
 * @delim: delimiter string pointer
 * Return: none
 */
void remdelimiter(char *strc, const char *delim)
{
	int i = 0, j = 0;

	if (isdelim(*(strc + i), delim) == 0)
		return;
	while (*(strc + i) != '\0')
	{
		if (isdelim(*(strc + i), delim) == 1)
			j++;
		else
			break;
		i++;
	}
strc = strc + j;
}
/**
 * isdelim - checks delimiter bytes with string character
 * @stringc: character to compare
 * @delim: pointer to delimiter string
 * Return: 1 match, 0(no match)
 */
int isdelim(char stringc, const char *delim)
{
	int i;

	i = 0;
	/* loop through all delimiter bytes, check for match*/
	while (*(delim + i) != '\0')
	{
		/* return 1 if match found or end of string */
		if (stringc == *(delim + i))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
/**
 * _strtok - custom implementation of the strtok() function
 * @str: string to be parsed
 * @delim: delimiting byte
 * Return: string of the new token
 */
char *_strtok(char *str, const char *delim)
{
	int i = 0, len = 0;
	char *ret;
	/* create a static pointer to store starting location of the function*/
	static char *strc;
	/* both str and strc are NULL=> error!! */
	if (delim == NULL)
	{
		perror("delimiter");
		exit(EXIT_FAILURE);
	}
	/*if str is NULL, str was specified on a previous call*/
	if (str != NULL)
		strc = str;
	/* if strc is null, end of etring has been reached */
	if (strc == NULL)
		return (NULL);
	/*get strc length, find delimiter (handle dulpicate delimiters)*/
	/*remdelimiter(strc, delim);*/
	len = strlen(strc);
	while (i <= len)
	{
		if (isdelim(*(strc + i), delim) == 1)
			break;
		i++;
	}
	/* change delimiter location to null byte '\0'*/
	*(strc + i) = '\0';
	/* store starting location to ret */
	ret = strc;
	/* end of string, one last match(i==len)*/
	if ((i + 1) == len || i == len)
		strc = '\0';
	/* else update starting location to after delim(now null byte) */
	else
		strc = strc + i + 1;
	return (ret);
}
