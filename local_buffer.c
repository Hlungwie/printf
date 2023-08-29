#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	
	/* Define flag characters and their corresponding values */	
	int j, curr_i;
	int flags = 0;

	/* Iterate through the format string to find and set flags */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
 /* Check if the current character matches any flag character */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)

			if (format[curr_i] == FLAGS_CH[j])
			{
				 /* Set the corresponding flag bit using bitwise OR */
				flags |= FLAGS_ARR[j];
				break;
			}

		/* If the character doesn't match any flag, exit the loop */
		if (FLAGS_CH[j] == 0)
			break;
	}
/* Update the index to the last processed character */
	*i = curr_i - 1;
/* Return the accumulated flags value */
	return (flags);
}
