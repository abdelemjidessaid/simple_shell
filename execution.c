#include "header_file.h"

/**
 * change_dir - Function that change the working directory.
 * @ar: Pointer of pointer to string that contains the environment varialbes.
 * Return: Void.
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
 * check_prog - Function that check if tokens contais a built-in program.
 * @line: Pointer to string that contains the commands.
 * @ar: Pointer of pointer to string that contains the commands.
 * @array: Pointer of pointer to string that contains the commands.
 * @newline: The copy of @line.
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
 * execute_one - function that excute programs and handles the errors.
 * @line: Included by user.
 * @ar: Array of commands.
 * @array: Array of commands.
 * @argv: Arrray of arguments that passed to the shell program.
 * @command_num: Number of commands contained in @line.
 * Return: 0 always success.
 */
int execute_one(
	char *line, char **ar, char *newline,
	char **array, char **argv, int command_num)
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
		while (wait_pid(-1, &status, 0) != child_id)
			;

	free(stat_buf);
	if (status == 0)
		errno = 0;
	if (status == 512)
		errno = 2;
	if (status == 65280)
		errno = 127;
	return (0);

}

/**
 * execute_path - Function that execute attempt to execute a
 * program using its path.
 * @p: Pointer the string contains the program name.
 * @ar: Array of paths.
 * Return: Void.
 */
void execute_path(char *p, char **ar)
{
	int status, p_len = 0, ar_len = 0;
	pid_t child;
	char *copy = NULL;

	while (p[p_len])
		p_len++;
	while (ar[0][ar_len])
		ar_len++;
	copy = malloc(sizeof(char) * (p_len + ar_len + 2));
	_strcpy(copy, p);
	_strcat(copy, "/");
	_strcat(copy, ar[0]);
	copy[p_len + ar_len + 1] = '\0';

	child = fork();
	if (child == 0)
	{
		if (access(copy, X_OK) == 0)
			execve(copy, ar, environ);
	}
	else
		while (waitpid(1, &status, 0) != child)
			;
	if (status == 0)
		errno = 0;
	free(copy);
}
