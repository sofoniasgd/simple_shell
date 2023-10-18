#include "shell.h"
/**
 * print_environment - Print the current environment variables.
 * @envp: An array of strings containing environment variables.
 */
void print_environment(char *envp[])
{
	int i = 0;
	size_t len;

	while (envp[i] != NULL)
	{
		len = _strlen(envp[i]);
		write(STDOUT_FILENO, envp[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

