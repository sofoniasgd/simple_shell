#include "shell.h"
/**
 * remove_comment - removes comment from line
 * @line: line string pointer
 * @nchars_read: previous string length
 * @nchars: number of characters in line
 * Return: none
 */
void remove_comment(char *line, size_t nchars, ssize_t *nchars_read)
{
	int i = 0, numchars = 0;

	numchars = (int)nchars;
	/* find  '#' */
	while (*(line + i) != '\0')
	{
		if (*(line + i) == '#')
			break;
		i++;
	}
	/* '#' is on the begining(comment line) */
	if (i == 0)
	{
		flushbuffer(line);
		return;
	}
	/* '#' at middle of string, fill rest of line with 0(null byte) */
	if (i <= numchars)
	{
		while (i <= numchars)
		{
			*(line + i) = '\0';
			i++;
		}
	}
/* update numchars_read */
*(nchars_read) = (size_t)i;
}

