#include <stdlib.h>
#include <stdio.h>
#include "main.h"


/**
 * _strlen -  returns the length of a string.
 * @s: is a pointer which is pointing to a  variable of char type
 *
 * Return: return the length of a string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strcmp -  compares two strings
 * @s1: is a variable of string type
 * @s2: is a variable of string type
 *
 * Return: 0 if equal, +ve if s1 is larger, -ve if s1 is smaller
 */

int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0; s1[j] != '\0' && s2[j] != '\0'; j++)
	{
		if (s1[j] - s2[j] != 0)
		{
			break;
		}
	}
	return (s1[j] - s2[j]);
	return (0);
}
/**
 * _strcpy - copies a string to a string
 * @dest: a buffer pointing to a string copied to
 * @src: a string pointed to by src
 *
 * Return: non
 */
char *_strcpy(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (src[i] != 0)
	{
		i++;
	}

	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
/**
 * _strdup - returns a pointer to a duplicate of the string
 * @str: is a pointer to the first char of a string
 *
 * Return: a pointer to the newly allocated string
 */
char *_strdup(char *str)
{
	char *ptr;
	int i, n;

	if (str == NULL)
		return (NULL);
	n = _strlen(str);
	ptr = malloc(sizeof(char) * (n + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
/**
 * _strcat - concatenates two strings.
 * @dest: a string which is a char pointer
 * @src: a string which is a char pointer
 *
 * Return: a concaternated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j, k, l;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	for (k = i, l = 0; k <  i + j; k++, l++)
		dest[k] = src[l];
	dest[k] = '\0';
	return (dest);
}
