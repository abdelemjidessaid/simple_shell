#include "header_file.h"

/**
 * count_tokens - Function that count the commands in a line.
 * @line: Pointer to string that contains the commands.
 * Return: Number of commands.
 */
int count_tokens(char *line)
{
	int count = 0, i, flag = 1;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ' || line[i] == 10 || line[i] == '\t')
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			++count;
		}
	}
	return (count);
}
