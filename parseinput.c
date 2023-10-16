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
	int i;
	/* copy command input into new location(lineptr_copy)*/
	*num_tokens = 0;
	lineptr_copy = malloc(sizeof(char) * (*nchars) + 1);
	if (lineptr_copy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strncpy(lineptr_copy, lineptr, (int)(*(nchars) + 1));
	/*_strncpy(char *dest, char *src, int n);*/
	printf("lineptr=%li | lineptr_copy=%li \n", _strlen(lineptr), _strlen(lineptr_copy));
	token = _strtok(lineptr, delim);
	while (token != NULL)
	{
		(*num_tokens)++;
		token = _strtok(NULL, delim);
	}
	/*(*num_tokens)++;*/
	printf("lineptr_Cpy=><<%s>>\nnum_tokens<<%i>>\n", lineptr_copy, *(num_tokens));
	*av = malloc(sizeof(char *) * (*num_tokens));
	if (*av == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = _strtok(lineptr_copy, delim);
	for (i = 0; i < *num_tokens; i++)
	{
		(*av)[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if ((*av)[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strncpy((*av)[i], token, (int)_strlen(token));
		printf("av[%i] strcpy=><<%s>>\n", i, (*av)[i]);
		token = _strtok(NULL, delim);
	}
	(*av)[i] = NULL;
	free(lineptr_copy);
	printf("exitparse\n");
}
