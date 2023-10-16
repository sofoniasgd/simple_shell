#include "shell.h"
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
	printf("freeing av[%i]\n", i);
/*	free(av[i]);*/
	i++;
}
}
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
		printf("line is <<<%s>>>\nnchars=><<%lu>>\n", lineptr, nchars_read);
		parseInput(lineptr, &av, &nchars_read, &num_tokens);
		/* making sure everything is working interms of input data processing */
		printf("back");
		i = 0;
		while (av[i] != NULL)
		{
			printf("av[%i]=><<%s>>\n", i, av[i]);
			i++;
		}
		printf("num_tokens=>%i\n", num_tokens);
		/*execute_command(argv[0], av, envp);*/
		i = 0;
		freeav(av);
		free(av);
	}
	return (0);
}
