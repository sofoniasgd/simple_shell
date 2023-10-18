#include "shell.h"
/**
 * append_path - looks for path and appends to command(TASK 3)
 * @av: pointer array of command and arguments
 * Return: always 0
 */
int append_path(char **av)
{
	char *command = NULL, *path = getenv("PATH"), *token, *path_copy, *full_path;
	/* check if command already has full path or not */
	command = av[0];
	if (_strchr(command, '/') == NULL)
	{
		/* get PATH value, extract directories(strtok) */
		path_copy = _strdup(path);
		token = _strtok(path_copy, ":");
		while (token != NULL)
		{
			/* for each directory, generate full path */
			/* and check if it exists (and can be accessed) */
			full_path = malloc(_strlen(token) + _strlen(command) + 2);
			if (full_path != NULL)
			{
				_strcpy(full_path, token);
				_strcat(full_path, "/");
				_strcat(full_path, command);
				if (access(full_path, X_OK) == 0)
				{
					/* file can be accessed, save full path to av[0]*/
					/* free av[0], reallocate to size of full_path and copy */
					free(av[0]);
					av[0] = malloc(sizeof(char) * _strlen(full_path));
					_strcpy(av[0], full_path);
					free(full_path);
					free(path_copy);
					return (0);
				}
				free(full_path);
			}
			token = _strtok(NULL, ":");
		}
		free(path_copy);
	}
	else
	{
		return (0);
	}
return (0);
}

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
 * main - Entry point for the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * @envp: An array of strings containing environment variables.
 * Return: Always returns 0.
 */

int main(int argc, char *argv[], char *envp[])
{
	ssize_t nchars_read;
	char *lineptr = NULL, **av = NULL;
	int num_tokens = 0, i = 0;

	(void)argc;
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
		parseInput(lineptr, &av, &nchars_read, &num_tokens);
		/*remove_comment(av, &num_tokens);*/
		if (_strcmp(av[0], "exit") == 0)
		{
			_exitstatus(argv, av);
		}
		else if (num_tokens == 1 && _strcmp(av[0], "env") == 0)
			print_environment(envp);
		execute_command(argv[0], av, envp);
		for (i = 0; i < num_tokens; i++)
		{
			free(av[i]);
		}
		free(av);
	}
	free(lineptr);
	return (0);
}
