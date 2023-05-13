#include "header_file.h"

/**
 * str_len - function that returns the length of strings.
 * 
 */
unsigned int str_len(char *str)
{
    unsigned int len = 0;

    while (str[len])
        len++;
    return (len);
}

/**
 * _strdup - function that duplicates a given string.
 * @str: pointer to the target string.
 * Return: a new string pointer, NULL if failed.
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
 * _strcmp - function that compares two strings.
 * @one: string one.
 * @two: string two.
 * Return: 1 if the same, 0 otherwise.
 */
int _strcmp(char *one, char *two)
{
    int i = 0;

    while (one[i] && two[i])
        if (one[i] != two[i])
            return (0);
    return (1);
}

/**
 * _strncmp - function that compares two string with a specific length.
 * @one: string one.
 * @two: string two.
 * @n: specific length.
 * Return: 1 if the same, 0 otherwise.
 */
int _strncmp(char *one, char *two, int n)
{
    int i = 0;

    while (one[i] && two[i] && i < n)
        if (one[i] != two[i])
            return (0);
    return (1);
}