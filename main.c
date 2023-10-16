#include "shell.h"
/**
 * main - Entry point for the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * @envp: An array of strings containing environment variables.
 * Return: Always returns 0.
 */

int main(int argc, char *argv[], char *envp[])
{
	size_t nchars_read;
	char *lineptr = NULL, **av = NULL;
	int num_tokens = 0, i = 0;

	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		lineptr = _getline();
		if (lineptr == NULL)
			exit(EXIT_SUCCESS);
		else if (strcmp(lineptr, "*") == 0)
			continue;
		nchars_read = _strlen(lineptr);
		printf("line b4 <<<%s>>>\nnchars=><<%lu>>\n", lineptr, nchars_read);
		remove_comment(lineptr, (nchars_read + 1));
		if (*lineptr == 0)
			continue;
		printf("line af <<<%s>>>\nnchars=><<%lu>>\n", lineptr, _strlen(lineptr));
		remove_comment(lineptr, (nchars_read + 1));
		parseInput(lineptr, &av, &nchars_read, &num_tokens);
		/* making sure everything is working interms of input data processing */
		i = 0;
		while (av[i] != NULL)
		{
			printf("av[%i]=><<%s>>\n", i, av[i]);
			i++;
		}

		printf("num_tokens=>%i\n", num_tokens);
		/*execute_command(argv[0], av, envp);*/
		freeav(av);
	}
	return (0);
}

/**
 * freeav - frees a pointer array's elements
 * @av: pointer array
 * Return: none
 */
void freeav(char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}
