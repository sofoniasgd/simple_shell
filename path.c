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
		printf("path=><%s>\npathcopy=><%s>\n", path, path_copy);
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
					av[0] = malloc(sizeof(char) * (_strlen(full_path) + 1));
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
