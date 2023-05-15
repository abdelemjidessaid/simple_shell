#include "header_file.h"

/**
 * _strcpy - Function to copy a string into a specific pointer.
 * @dest: Pointer of destination.
 * @src: Pointer of source.
 * Return: Number of bytes copied.
 */
int _strcpy(char *dest, char *src)
{
	int len = 0, i = 0;

	if (!src)
		return (0);
	len = str_len(src);
	if (!dest)
		dest = malloc(sizeof(char) * (len + 1));
	for (i; i < len; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (len);
}

/**
 * _strcat - Function to concatenate strings.
 * @dest: Pointer to destination string.
 * @ad: Pointer to addition string.
 * Return: Void.
*/
void _strcat(char *dest, char *ad)
{
	int d_len = 0, a_len = 0, i, j;

	if (!dest || !ad)
		return;
	d_len = str_len(dest);
	a_len = str_len(ad);

	for (j = d_len - 1, i = 0; i < a_len; i++, j++)
		dest[j] = ad[i];
	dest[j] = '\0';
}

/**
 * _putchar - function that prints a single character.
 * @c: the character.
 * Return: number of bytes that is printed out.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
