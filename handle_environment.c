#include "header_file.h"
/**
 * find_path - Function that searches for a path in array of paths.
 * @p: Pointer to string contains path.
 * @ar: Array of paths.
 * Return: 1 If found, 0 otherwise.
 */
int find_path(char *p, char **ar)
{
	struct dirent *dir;
	int reached = 0, found = 0;

	p = strtok(p, ":");
	while (p && !reached)
	{
		DIR *dr = opendir(p);

		if (dr == NULL)
			return (0);
		while ((dir = readdir(dr)) != NULL)
		{
			if (_strcmp(dir->d_name, ar[0]))
			{
				execute_path(p, ar);
				found = 1;
				reached = 1;
				break;
			}
		}
		closedir(dr);
		if (!reached)
			p = strtok(NULL, ":");
	}
	return (found);
}
/**
 * find_file - Function that looking for a file in PATH.
 * @ar: Pointer of pointers to string contains file paths.
 * Return: 1 if file found on path, 0 otherwise.
 */
int find_file(char **ar)
{
	int i = 0, found = 0;
	char *p = NULL, *path = NULL;

	while (environ[i])
	{
		if (_strncmp("PATH=", environ[i], 5))
		{
			path = _strdup(environ[i]);
			strtok(path, "=");
			p = strtok(NULL, "=");
			found = find_path(p, ar);
			break;
		}
		i++;
	}
	free(path);
	return (found);
}
