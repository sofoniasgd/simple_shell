#include "shell.h"
/**
 * finder - finds location of '#'
 * @av: tokenized command array
 * @i: token location in array
 * @j: character location in token
 * Return: always 0
 */
int finder(char **av, int *a, int *b)
{
	int i = 0,j;
	/* find location of comment indicator '#' */
	while (*av[i] != '\0')
	{
		j = 0;
		while (*(av[i] + j ) != '\0')
		{
			if (*(av[i] + j) == '#')
			{
				*a = i;
				*b = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
/**
 * remove_comment - removes comment from line
 * @av: tokenized command input
 * @num_tokens: number of tokens in command
 * Return: flag ()
 */
int remove_comment(char **av, int *num_tokens)
{
	int i = -1, j = -1;

	finder(av, &i, &j);
	/* no comment!, return */
	if (i == -1 && j == -1)
		return;
	/*command line is a comment(starts with '#')*/
	else if (i == 0 && j == 0)
	{
		free(av[i]);
		*num_tokens = 0;
		av[i] = NULL;
		i++;
	}
	else
	{
		*(av[i] + j) = '\0';
		j++;
		while (*(av[i] + j) != '\0')
		{
			*(av[i] + j) = '\0';
			j++;
		}
		i++;
	}
	if (i >= 0)
		*num_tokens = i;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	av[i] = NULL;
	return (0);
}
