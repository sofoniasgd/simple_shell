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
	int num_tokens = 0;

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
		/* remove comments */
		remove_comment(lineptr, (nchars_read + 1), &nchars_read);
		if (*lineptr == 0)
			continue;
		/* tokenize command line */
		nchars_read = _strlen(lineptr);
		parseInput(lineptr, &av, &nchars_read, &num_tokens);
		/* check for builtin functions => exit, cd,  env */
		/* else append path and execute commend */
		if (builtin_functions(av, argv, envp) == 1)
			continue;
		else
			execute_command(argv[0], av, envp);
		/* free allocated memory */
		freeav(av);
	}
	return (0);
}
/**
 * builtin_functions - checks for builtin functions
 * @av: tekenized command array
 * @argv: argument array to main
 * @envp: enviroment variable pointer
 * Return: status flag (0 for not found, 1 for found and executed)
 */
int builtin_functions(char **av, char *argv[], char *envp[])
{
	int flag = 0;
	/* check for each case and call respective function */
	if (_strcmp(av[0], "exit") == 0)
	{
		flag = 1;
		_exitstatus(argv, av);
	}
	else if (_strcmp(av[0], "env") == 0)
	{
		flag = 1;
		print_environment(envp);
	}
	/* return status flag(1 if function found, 0 otherwise)*/
	return (flag);
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
