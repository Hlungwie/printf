#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Initialize variables */
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
/* If the pointer is NULL, print "(nil)" and return */
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
/* Place null terminator at the end of the buffer */
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	 /* Convert the pointer address to hexadecimal representation */

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
/* Handle padding and extra characters based on formatting flags */
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;	/*Adjust index to point to the beginning of the formatted string*/
/* Call a function to write the formatted output and return the result */
	return (write(1, &buffer[i], BUFF_SIZE - i - 1));
		(write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Initialize variables */
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	 /* If the input string is NULL, print "(null)" and return */
	if (str == NULL)
		return (write(1, "(null)", 6));
	/* Loop through the input string */
	while (str[i] != '\0')
	{
		/* Check if the character is printable */
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		/*If not printable, append hexadecimal code */
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}
	/* Place null terminator at the end of the buffer */
	buffer[i + offset] = '\0';
	/* Write the formatted output and return the result */
	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	  /* Initialize variables */
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	/* Retrieve the string argument from variable arguments */
	str = va_arg(types, char *);
	/* If the string is NULL, handle as specified */
	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	/* Calculate the length of the string */
	for (i = 0; str[i]; i++)
		;
	/* Loop through the string in reverse order and print characters */

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];
	/* Print each character and increment the count */
		write(1, &z, 1);
		count++;
	}
	/* Return the count of printed characters */
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Initialize variables */
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	/* Retrieve the string argument from variable arguments */
	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	/* If the string is NULL, handle as specified */
	if (str == NULL)
		str = "(AHYY)";
	/* Loop through the input string */
	for (i = 0; str[i]; i++)
	{
		/* Check for each character in the input array */
		for (j = 0; in[j]; j++)
		{
			/* If a match is found, replace with corresponding rot13 character */
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		 /* If no match is found, keep the character as is */
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	/* Return the count of printed characters */
	return (count);
}
