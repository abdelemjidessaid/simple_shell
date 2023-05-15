#include "header_file.h"

/**
 * count_tokens - Function that count the commands in a line.
 * @line: Pointer to string that contains the commands.
 * Return: Number of commands.
 */
int count_tokens(char *line)
{
	int i, found = 1, count = 0;

	while (line[i])
	{
		if (line[i] == ' ' || line[i] == 10 || line[i] == '\t')
			found = 1;
		else if (found)
		{
			found = 0;
			++count;
		}
		i++;
	}

	return (count);
}
