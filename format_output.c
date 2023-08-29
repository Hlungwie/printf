#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];
 /* Check if the format string is NULL */
	if (format == NULL)
		return (-1);
 /* Start the variable argument list */
	va_start(list, format);
/* Loop through the format string */
	for (i = 0; format && format[i] != '\0'; i++)
	{
		/* If character is not '%', add to buffer and print if necessary */
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			/* Print buffer if it's full */
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/*Increment printed character count*/
			printed_chars++;
		}
		else
		{
			/* Print buffer before handling the format specifier */
			print_buffer(buffer, &buff_ind);
			 /* Retrieve formatting information */
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			 /* Move past '%' */
			++i;

			/* Handle printing based on format specifier */
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);

			 /* Check for printing error */
			if (printed == -1)
				return (-1);
			/* Increment printed character count */
			printed_chars += printed;
		}
	}
/* Print any remaining buffer contents */
	print_buffer(buffer, &buff_ind);
/* End the variable argument list */
	va_end(list);
/* Return the total number of printed characters */
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
