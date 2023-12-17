#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * is_dlm - check if a char is a delimiter
 * @c: the char to check
 * @dlm: a sting containing delimiters
 * Return: 1 if char found and 0 otherwise
 */

int is_dlm(int c, const char *dlm)
{
	int k;

	for (k = 0; dlm[k] != 0; k++)
	{
		if (c == (char)dlm[k])
			return (1);
	}
	return (0);
}

/**
 * _strtok - divide a string into tokens
 * @str: a string to be divided
 * @dlm: a string containing delimiters
 * Return: the current token
 */

char *_strtok(char *str, char *dlm)
{
	static char *ptr;
	static char *temp;
	int j;

	if (str != NULL)
		ptr = str;

	if (ptr == NULL)
		return (NULL);

	/*find a delimter at the beginning of a string*/

	while (*ptr != '\0' && is_dlm((int)*ptr, dlm))
	{
		ptr++;
	}

	/*move ptr to the end of the current token*/

	for (j = 0; ptr[j] != '\0'; j++)
	{
		if (is_dlm((int)ptr[j], dlm))
		break;
	}
	temp = ptr;
	if (*ptr == '\0')
		return (NULL);

	/**
	 * add the null terminator at the end of the token
	 * and move the pointer to the beginning of the next
	 * token
	 */
	ptr[j] = '\0';
	ptr += j + 1;
	return (temp);
}
