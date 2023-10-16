#include "shell.h"
/**
 * parseInput - Tokenize the input line into individual tokens.
 * @lineptr: The input line to be tokenized.
 * @av: A pointer to a pointer that will store the tokenized tokens.
 * @nchars: A pointer to the number of characters read in the input line.
 * @num_tokens: A pointer to an integer that will store the number of tokens.
 */
void parseInput(char *lineptr, char ***av, size_t *nchars, int *num_tokens)
{
	char *lineptr_copy = NULL, *token;
	const char *delim = " \n";
	int i, len = 0;
	/* copy command input into new location(lineptr_copy)*/
	*num_tokens = 0;
	lineptr_copy = malloc(sizeof(char) * ((*nchars) + 1));
	if (lineptr_copy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strncpy(lineptr_copy, lineptr, (int)(*(nchars) + 1));
	token = _strtok(lineptr, delim);
	while (token != NULL)
	{
		(*num_tokens)++;
		token = _strtok(NULL, delim);
	}

	*av = malloc(sizeof(char *) * ((*num_tokens) + 1));
	if (*av == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = _strtok(lineptr_copy, delim);
	for (i = 0; i < *num_tokens; i++)
	{
		len = (int)_strlen(token);
		(*av)[i] = malloc(sizeof(char) * (len + 1));
		if ((*av)[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strncpy((*av)[i], token, (len + 1));
		token = _strtok(NULL, delim);
	}
	(*av)[i] = NULL;
	free(lineptr_copy);
}
