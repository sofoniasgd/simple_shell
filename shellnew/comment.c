#include "shell.h"
/**
 * finder - finds location of '#'
 * @av: tokenized command array
 * @i: token location in array
 * @j: character location in token
 * Return: always 0
 */
int finder(char **av, int *i, int *j)
{
	int t = 0, c = 0;
	/* find location of comment indicator '#' */
	while (*av[t] != '\0')
	{
		j = 0;
		while (*(av[t] + c) != '\0')
		{
			if (*(av[t] + c) == '#')
			{
				printf("found\n");
				*i = t;
				*j = c;
				printf("i=%i  j=%i\n", t, c);
				return (0);
			}
			c++;
		}
		t++;
	}
	return (0);
}
/**
 * remove_comment - removes comment from line
 * @av: tokenized command input
 * @num_tokens: number of tokens in command
 * Return: none
 */
void remove_comment(char **av, int *num_tokens)
{
	int i = -1, j = -1;

	finder(av, &i, &j);
	if (i == -1 && j == -1)
	{
		printf("no comment!!\n");
		return;
	}
	/*command is a comment(starts with '#')*/
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
	if (i == 0)
		*num_tokens = 0;
	else
		*num_tokens = i;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	av[i] = NULL;
}
