#include "header_file.h"
/**
 * handle_number - Function that prints a number recursively.
 * @num: The number specifier.
 * Return: Void.
 */
void handle_number(int num)
{
	if (num > 0)
		handle_number(num / 10);
	if (num != 0)
		_putchar('0' + (num % 10));
}
/**
 * print_str - Function that prints a string from an array of arguments.
 * @args: Array of arguments.
 * Return: Number of bytes that is printed out.
 */
int print_str(va_list *args)
{
	int i;
	char *line;

	line = va_arg(*args, char *);
	while (line[i] != '\0')
		_putchar(line[i++]);

	return (i);
}
/**
 * print_digit - Function that prints digits.
 * @args: Array of arguments.
 * Return: Number of bytes that is printed out.
 */
int print_digit(va_list *args)
{
	int bytes = 0, num = va_arg(*args, int), tmp = num, last = 1;

	if (tmp < 0)
		tmp *= -1;
	while (tmp > 0)
	{
		tmp /= 10;
		bytes++;
	}
	if (num < 0)
	{
		_putchar('-');
		bytes++;
		last = num % 10;
		num /= -10;
	}
	else if (num == 0)
	{
		_putchar('0');
		return (bytes);
	}
	handle_number(num);
	if (last < 0)
		_putchar('0' - last);

	return (bytes);
}
/**
 * check_format - Function that checks formated string for the print function.
 * @args: Pointer to an array of arguments.
 * @format: Pointer to a formated string.
 * @i: The index of character to check.
 * Return: The number of bytes that is printed.
 */
int check_format(va_list *args, const char *format, int i)
{
	int a = 0, b = 0;
	frmt data_types[] = {
		{"s", print_str},
		{"d", print_digit},
		{"i", print_digit},
		{NULL, NULL}
	};

	i++;
	if (format[i] == ' ')
		while (format[i] == ' ')
			i++;
	if (format[i] == '%')
	{
		_putchar('%');
		return (1);
	}
	if (format[i] == 'n')
	{
		_putchar('\n');
		return (1);
	}

	while (data_types[a].type && *(data_types[a].data_type) != format[i])
		a++;

	if (data_types[a].type == NULL)
		return (-1);
	b = data_types[a].type(args);

	return (b);
}


/**
 * print - Function that prints the formated strings.
 * @format: Pointer to a special string.
 * Return: Number of bytes that is printed out.
 */
int print(char *format, ...)
{
	int i = 0, check = 0, count = 0;
	va_list args;
	frmt special[] = {
		{"%", check_format},
		{"\\", check_format},
		{NULL, NULL}
	};

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == *(special[0].data_type))
		{
			check += special[0].type(&args, format, i);
			if (check == -1)
				return (-1);
			count += check;
			i++;
			while (format[i] == ' ')
				i++;
			check = 1;
		}
		if (!check)
		{
			_putchar(format[i]);
			count++;
		}
		check = 0;
		i++;
	}

	va_end(args);
	return (count);
}
