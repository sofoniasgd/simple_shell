#include "shell.h"
/**
 * flushbuffer - flushes buffer
 * @buff: pointer to buffer
 * Return: none
 */
void flushbuffer(char *buff)
{
int i = 0;
while (i < 1024)
{
	*(buff + i) = 0;
	i++;
}
}
/**
 * pipe_getline - getline implementation in non-iteactive mode
 * Return: none
 */
char *pipe_getline()
{
	static char buffer[1024];
	size_t start = 0, length = 0;
	int i = 0, sub = 0, len = 0;
	char *ret;

	flushbuffer(buffer);
	ret = fgets(buffer, sizeof(buffer), stdin);
	if (ret == NULL)
		return (NULL);

	len = strlen(buffer);
	while (len > 0 && buffer[len - 1] == '\n')
	{
		buffer[len - 1] = '\0';
		len--;
	}
	while (buffer[start] != '\0' && buffer[start] == ' ')
	{
		start++;
	}
	if (start == 1023)
	{
		return (NULL);
	}
	length = _strlen(buffer + start);

	if (length == 0)
		return (NULL);

	i = length;
	while (i > 0 && buffer[start + i - 1] == ' ')
	{
		sub++;
		i--;
	}
	buffer[start + (length - sub)] = '\n';
	buffer[start + (length - sub) + 1] = '\0';

	return (buffer + start);
}
/**
 * _getline - custom getline() implementation
 * uses read() function
 * Return: char pointer to read line
 */
char *_getline()
{
	ssize_t len;
	/* use static buffer with max size 1024 and flsuh it */
	static char buff[1024];

	if (!isatty(STDIN_FILENO))
	{
		return (pipe_getline());
	}
	flushbuffer(buff);
	/* call read and handle errors */
	len = read(STDIN_FILENO, buff, sizeof(buff));
	if (len == -1)
	{
		/* read failure, done writing data */
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	/* id len == 0, EOF is reached with/out input */
	else if (len == 0)
	{
		/* EOF with notext exit program */
		if (buff[0] == '\0')
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		return (buff);
	}
	/* normal input */
	return (buff);
}
