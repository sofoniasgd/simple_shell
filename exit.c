#include "shell.h"
/**
 * _exitstatus- Exit the shell with a specified status code.
 * @av: An array of strings containing the "exit" command
 *		and its argument (if any).
 * @argv: argument vector of main
 * Return: none
 */
void _exitstatus(char **argv, char **av)
{
	char errmessage[256];
	int status_code;

	errmessage[0] = '\0';
	if (av[1])
	{
		status_code = _atoi(av[1]);
		/* if exit code is invalid */
		if (status_code <= 0)
		{
			strcat(errmessage, argv[0]);
			strcat(errmessage, ": 1: ");
			strcat(errmessage, av[0]);
			strcat(errmessage, ": Illegal number: ");
			strcat(errmessage, av[1]);
			strcat(errmessage, "\n");
			write(STDERR_FILENO, errmessage, strlen(errmessage));
			status_code = 2;
		}
		if (status_code > 255)
			status_code = status_code % 256;
		/* free memory and exit with code */
		free(av[0]);
		free(av[1]);
		free(av);
		exit(status_code);
	}
	else
	{
		free(av[0]);
		free(av);
		exit(0);
	}
}
