#include "shell.h"
/**
 * parseInput - Tokenize the input line into individual tokens.
 * @lineptr: The input line to be tokenized.
 * @av: A pointer to a pointer that will store the tokenized tokens.
 * @nchars: A pointer to the number of characters read in the input line.
 * @num_tokens: A pointer to an integer that will store the number of tokens.
 */
void parseInput(char *lineptr, char ***av, ssize_t *nchars, int *num_tokens)
{
	char *lineptr_copy = NULL, *token;
	const char *delim = " \n";
	int i;
	/* copy command input into new location(lineptr_copy)*/
	*num_tokens = 0;
	lineptr_copy = malloc(sizeof(char) * (*nchars) + 1);
	if (lineptr_copy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(lineptr_copy, lineptr);
	token = _strtok(lineptr, delim);
	while (token != NULL)
	{
		(*num_tokens)++;
		token = _strtok(NULL, delim);
	}
	/*(*num_tokens)++;*/
	*av = malloc(sizeof(char *) * (*num_tokens));
	if (*av == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = _strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		(*av)[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if ((*av)[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy((*av)[i], token);
		token = _strtok(NULL, delim);
	}
	(*av)[i] = NULL;
	free(lineptr_copy);
}
