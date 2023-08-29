#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Initialize the index for the buffer */
	int i = BUFF_SIZE - 2;

	 /* Retrieve the unsigned long integer from variable argument list */
	unsigned long int num = va_arg(types, unsigned long int);

	/* Convert the size of the integer using a custom function */
	num = convert_size_unsgnd(num, size);

	 /* If the number is 0, place '0' in the buffer */
	if (num == 0)
		buffer[i--] = '0';
	/* Place null terminator at the end of the buffer */
	buffer[BUFF_SIZE - 1] = '\0';
	 /* Convert the number to digits and place them in reverse order in the buffer */
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	/* Increment the index to point to the beginning of the formatted string */
	i++;
	/* Call a function to write the formatted output and return the result */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Initialize the index for the buffer */

	int i = BUFF_SIZE - 2;

	/* Retrieve the unsigned long integer from variable argument list */
	unsigned long int num = va_arg(types, unsigned long int);
	/* Store the initial number for potential use */
	unsigned long int init_num = num;
	/* Mark the width argument as unused */
	UNUSED(width);
	/* Convert the size of the integer using a custom function */
	num = convert_size_unsgnd(num, size);
	 /* If the number is 0, place '0' in the buffer */
	if (num == 0)
		buffer[i--] = '0';
	/* Place null terminator at the end of the buffer */
	buffer[BUFF_SIZE - 1] = '\0';
	/* Convert the number to octal digits and place them in reverse order in the buffer */
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	 /* If the 'hash' flag is set and the initial number is not 0, add '0' prefix */
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	/* Increment the index to point to the beginning of the formatted string */
	i++;
	 /* Call a function to write the formatted output and return the result */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	/* Initialize the index for the buffer */
	int i = BUFF_SIZE - 2;
	 /* Retrieve the unsigned long integer from variable argument list */
	unsigned long int num = va_arg(types, unsigned long int);
	/* Store the initial number for potential use */
	unsigned long int init_num = num;
	/* Mark the width argument as unused */
	UNUSED(width);
	/* Convert the size of the integer using a custom function */
	num = convert_size_unsgnd(num, size);
	 /* If the number is 0, place '0' in the buffer */
	if (num == 0)
		buffer[i--] = '0';
	 /* Place null terminator at the end of the buffer */
	buffer[BUFF_SIZE - 1] = '\0';
	/* Convert the number to hexadecimal digits and place them in reverse order in the buffer */
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

/* If the 'hash' flag is set and the initial number is not 0, add the flag character and '0' prefix */
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	/* Increment the index to point to the beginning of the formatted string */
	i++;
	 /* Call a function to write the formatted output and return the result */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
