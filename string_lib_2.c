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
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
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

	for (j = d_len, i = 0; i < a_len; i++, j++)
		dest[j] = ad[i];
	dest[j] = '\0';
}

/**
 * _putchar - Function that prints a single character.
 * @c: The character specifier.
 * Return: Number of bytes that is printed out.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _atoi - function that converts a string number to integer.
 * @str: pointer to the string number.
 * Return: number if success, -1 otherwise. 
 */
int _atoi(char *str)
{
	int i = 0, sign = 1, num = 0;

	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		else
			return 0;
	}

	return num * sign;
}
