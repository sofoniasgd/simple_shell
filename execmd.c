#include "shell.h"
/**
 * execmd - Execute a command in a child process.
 * @av: An array of strings containing the command and its arguments.
 * @envp: An array of strings containing environment variables.
 */
void execmd(char **av, char **envp)
{
	char *command = NULL;
/* execute command, av & av[0] check might be redundant */
	if (av && av[0])
	{
		command = av[0];
		execve(command, av, envp);
	}
	else
		exit(EXIT_FAILURE);
}

