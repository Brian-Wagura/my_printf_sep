#include "main.h"

/**
 * handle_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @x: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int handle_width(const char *format, int *x, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *x + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*x = curr_i - 1;
	return (width);
}
