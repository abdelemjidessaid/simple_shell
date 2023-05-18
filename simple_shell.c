#include "header_file.h"

/**
 * main - Entry point of the simple shell program.
 * @argc: argument count.
 * @argv: argument array.
 * Return: 0 always success.
 */
int main(int argc, char *argv[])
{
	size_t buf_size = 0;
	char *line = NULL;
	int ret_v, token_num = 0, command_num = 1, interactive;

	signal(SIGINT, SIG_IGN);
	interactive = isatty(STDIN_FILENO);

	if (!interactive && argc == 1)
	{
		while (getline(&line, &buf_size, stdin) > 0)
		{
			token_num = count_tokens(line);
			line_parser(line, token_num, argv, command_num);
			line = NULL;
		}
		free(line);
		return (0);
	}
	while (interactive)
	{
		write(STDOUT_FILENO, "($) ", 4);
		token_num = 0;
		ret_v = getline(&line, &buf_size, stdin);

		if (ret_v < 0)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		token_num = count_tokens(line);
		line_parser(line, token_num, argv, command_num);
		command_num++;
		line = NULL;
	}

	return (0);
}
