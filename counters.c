#include "header_file.h"

/**
 * count_tokens - function that count the commands in a line.
 * @line: pointer to string that contains the commands.
 * Return: number of commands.
 */
int count_tokens(char *line)
{
    int i, found = 1, count = 0;

    while (line[i])
    {
        if (line[i] == ' ' || line[i] == 10 || line == '\t')
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