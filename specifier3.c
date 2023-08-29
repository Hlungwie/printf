#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	/* Initialize the index to the next character after '%' */
	int curr_i = *i + 1;
	/* Initialize precision to a default value */
	int precision = -1;
	/* Check if the next character is not '.' (indicating precision) */
	if (format[curr_i] != '.')
		return (precision);
	 /* Initialize precision to 0 since '.' indicates presence of precision */
	precision = 0;
	/* If the current character is a digit, update precision */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			/* Multiply the existing precision by 10 and add the digit value */
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		/* If the current character is '*', retrieve precision from arguments */
		else if (format[curr_i] == '*')
		{
			/* Move past '*' and retrieve precision from variable argument list */
			curr_i++;
			precision = va_arg(list, int);
			break;/*Exit the loop after retrieving precision
                */
		}
		/* If the character is not a digit or '*', exit the loop */
		else
			break;
	}
/* Update the index to the last processed character */
	*i = curr_i - 1;
/* Return the calculated precision value */
	return (precision);
}
