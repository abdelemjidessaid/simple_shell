#include "header_file.h"

/**
 * free_parser - function that frees the pointers that is used in line_parser.
 * @line: pointer to string that contains commands.
 * @newline: copy of @line.
 * @ar: array of pointers that contains each command in @line.
 * @array: the same of @ar.
 */
void free_parser(char *line, char *newline, char **ar, char **array)
{
    int i = 0;

    if (ar)
    {
        while (ar[i])
            free(ar[i++]);
        free(ar);
    }
    if (newline)
        free(newline);
    if (line)
        free(line);
    if (array)
        free(array);
}