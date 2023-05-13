#include "header_file.h"

/**
 * line_parser - function that parse line and execute the file if it is
 * a program.
 * @line: pointer to string that contains the command included by user.
 * @token_num: number of segments in command line included.
 * @argv: array of arguments given to program.
 * @command_num: number of commands that is included.
 * Return: void.
 */
void line_parser(char *line, int token_num, char **argv, int command_num)
{
    int i = 0, is_prog, x = 0;
    char *p = NULL, *newline = NULL, **array = NULL, **ar = NULL;
    char *ignore = " \v\t\r\f\n";

    array = malloc(sizeof(char *) * token_num);
    newline = _strdup(line);
    p = strtok(line, ignore);

    if (!p)
    {
        free_parser(line, newline, ar, array);
        return (0);
    }

    while (p)
    {
        array[i++] = p;
        p = strtok(NULL, ignore);
    }
    ar = malloc(sizeof(char *) * (token_num + 1));
    for (i = 0; i < token_num; i++)
        ar[i] = _strdup(array[i]);
    ar[i] = NULL;
    is_prog = check_prog(line, ar, array, newline);
    if (!is_prog)
        x = execute_one(line, ar, newline, array, argv, command_num);
    free_parser(line, newline, ar, array);

    return (x);
}