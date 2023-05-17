#include "header_file.h"

/**
 * str_len - Function that returns the length of strings.
 * @str: Pointer to the string.
 * Return: Length of string.
 */
unsigned int str_len(char *str)
{
	unsigned int len = 0;

	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strdup - Function that duplicates a given string.
 * @str: Pointer to the target string.
 * Return: A new string pointer, NULL if failed.
 */
char *_strdup(char *str)
{
	int len, i;
	char *p;

	if (str)
	{
		len = str_len(str);
		p = malloc(sizeof(char) * (len + 1));
		if (p)
		{
			for (i = 0; i < len; i++)
				p[i] = str[i];
			p[i] = '\0';
			return (p);
		}
		else
			return (NULL);
	}
	return (NULL);
}

/**
 * _strcmp - Function that compares two strings.
 * @one: String one.
 * @two: String two.
 * Return: 1 if the same, 0 otherwise.
 */
int _strcmp(char *one, char *two)
{
	int i = 0, len1, len2;

	len1 = str_len(one);
	len2 = str_len(two);
	if (len1 != len2)
		return (0);
	while (one[i] != '\0' && two[i] != '\0')
	{
		if (one[i] != two[i])
			return (0);
		i++;
	}

	return (1);
}

/**
 * _strncmp - Function that compares two string with a specific length.
 * @one: String one.
 * @two: String two.
 * @n: Specific length.
 * Return: 1 if the same, 0 otherwise.
 */
int _strncmp(char *one, char *two, int n)
{
	int i = 0;

	if (!one || !two)
		return (0);
	while (one[i] != '\0' && two[i] != '\0' && i < n)
	{
		if (one[i] != two[i])
			return (0);
		i++;
	}

	return (1);
}

/**
 * _puts - Function that prints a string to the standard output.
 * @str: Pointer to the string.
 * Return: Void.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
		write(STDOUT_FILENO, &str[i++], 1);
	write(STDOUT_FILENO, "\n", 1);
}
