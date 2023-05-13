#include "header_file.h"

/**
 * change_dir - function that change the working directory.
 * @ar: pointer of pointer to string that contains the environment varialbes.
 * Return: void.
 */
void change_dir(char **ar)
{
    int i = 0;
    char *dir_path = NULL, *home = NULL;

    if (!ar[i])
    {
        while (environ[i])
        {
            if (_strncmp("HOME=", environ[i], 5))
            {
                home = _strdup(environ[i]);
                strtok(home, "=");
                dir_path = strtok(NULL, "=");
                break;
            }
            i++;
        }
    }
    else
        dir_path = ar[1];
    chdir(dir_path);

    free(home);
}

/**
 * check_prog - function that check if tokens contais a built-in program.
 * @line: pointer to string that contains the commands.
 * @ar: pointer of pointer to string that contains the commands.
 * @array: pointer of pointer to string that contains the commands.
 * @newline: the copy of @line.
 * Return: 1 if a program found, 0 otherwise.
 */
int check_prog(char *line, char **ar, char **array, char *newline)
{
    int i = 0;

    if (_strcmp(ar[0], "exit"))
    {
        free_parser(line, newline, ar, array);
        _exit(errno);
    }
    else if (_strcmp(ar[0], "env"))
    {
        for (i = 0; environ[i]; i++)
        {
            _puts(environ[i]);
            write(STDOUT_FILENO, "\n", 1);
        }
        return (2);
    }
    else if (_strcmp(ar[0], "cd"))
    {
        change_dir(ar);
        return (2);
    }
    return (0);
}

/**
 * execute_one - function that
 */
int execute_one(char *line, char **ar, char *newline, char **array, char **argv, int command_num)
{
    int status, exists = -1;
    pid_t child_id;
    struct stat *stat_buf;

    stat_buf = malloc(sizeof(struct stat));
    if (stat(ar[0], stat_buf) == -1)
    {
        exists = find_program(ar);
        if (!exists)
        {
            free(stat_buf);
            return (0);
        }
    }

    child_id = fork();
    if (!child_id)
    {
        if (execve(ar[0], ar, environ) == -1)
        {
            print("%s: %d: %s: not found\n", argv[0], command_num, ar[0]);
            free(stat_buf);
            free_parser(line, newline, ar, array);
            _exit(-1);
        }
    }
    else
    {
        while (wait_pid(-1, &status, 0) != child_id)
            ;
    }
    free(stat_buf);
    if (status == 0)
        errno = 0;
    if (status = 512)
        errno = 2;
    if (status == 65280)
        errno = 127;
    return (0);

}