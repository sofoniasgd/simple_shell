#include "shell.h"

/**
 * execute_command - Execute a command with its arguments.
 * @av: An array of strings containing the command and its arguments.
 * @argv: a string of first argument of main function
 * @envp: An array of strings containing environment variables.
 */
void execute_command(char *argv, char **av, char *envp[])
{
	char errmessage[256];
	pid_t pid;
	int status, exitstat;

	errmessage[0] = '\0';
	/* check if av exists or command exists(parseint worked)*/
	if (!av || !av[0])
		exit(2);
	/* handle path before fork==> call append path */
	append_path(av);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execmd(av, envp);
		strcat(errmessage, argv);
		strcat(errmessage, ": 1: ");
		strcat(errmessage, av[0]);
		strcat(errmessage, ": not found\n");
		write(STDERR_FILENO, errmessage, strlen(errmessage));
		exit(EXIT_FAILURE);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
		{
			exitstat = WEXITSTATUS(status);
			if (exitstat != 0)
				exit(exitstat);
		}
	}
}
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

