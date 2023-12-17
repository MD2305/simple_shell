#include <stdlib.h>
#include <stdio.h>
#include "main.h"


/**
 * _getline - reads input from the sream and store it in a buffer
 * @lineptr: a pointer to a string
 * @n: number of bytes to be read
 * @stream: a file to read from
 * Return: number of bytes read from stream
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t  i = 0;


	if (*lineptr == NULL || *n == 0)
	{
		*n = 1024;
		*lineptr = malloc(sizeof(char) * *n);
	if (*lineptr == NULL)
		return (-1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		(*lineptr)[i] = (char)c;
		i++;
		if (c == '\n')
			break;
		if (i == *n - 1)
		{
			*lineptr = realloc(*lineptr, sizeof(char) * (2 * *n));
			if (*lineptr == NULL)
				return (-1);
			*n *= 2;
		}
	}
	if (c == EOF && i == 0)
		return (-1);
	return ((ssize_t)i);
}
