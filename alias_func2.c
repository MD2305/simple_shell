#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * print_alias - print the alias list or a certain element
 * @s: the specific name to be printed
 * @name: a pointer to the array of names
 * @value: a pointer to the array of values
 *
 * Return: always 0
 */
int print_alias(char *s, char ***name, char ***value)
{
	int i;

	for (i = 0; (*name)[i] != NULL; i++)
	{
		if (s == NULL)
			printf("%s='%s'\n", (*name)[i], (*value)[i]);
		else
		{
			if (strcmp((*name)[i], s) == 0)
			{
				printf("%s='%s'\n", (*name)[i], (*value)[i]);
				return (0);
			}
		}
	}
	return (0);
}
/**
 * alias_cont - check parameters and send to corresponding functions
 * @arg: the array of tokens
 * @name: a pointer to the array of names
 * @value: a pointer to the array of values
 * @mode: the mode of processing
 *
 * Return: -1 in failure, 1 in success.
 */

int alias_cont(char **arg, char ***name, char ***value, int mode)
{
	if (arg == NULL)
	{
		if (name && value)
		{
			free_grid(*name);
			free_grid(*value);
		}
		return (0);
	}
	if (mode == 1)
	{
		alias_sub(arg, name, value);
		return (0);
	}
	if (!arg[1] || (strcmp(arg[1], "-p") == 0))
	{
		print_alias(NULL, name, value); /* prints complete existing databse t*/
		return (0);
	}
	return (1);
}
/**
 * _alias - aliases allow a string to be substituted for a word
 * @arg: the array of tokens
 * @mode: the mode of processing
 *
 * Return: -1 in failure, 1 in success.
 */
int _alias(char **arg, int mode)
{
	static char **name, **value;
	int i = 0, j = 1, fg;

	if (name == NULL)
	{
		name = malloc(sizeof(char *) * 1);
		if (!name)
			return (-1);
		name[0] = NULL;
	}
	if (value == NULL)
	{
		value = malloc(sizeof(char *) * 1);
		if (!value)
			return (-1);
		value[0] = NULL;
	}
	i = alias_cont(arg, &name, &value, mode);
	if (i == 1)
	{
		while (arg[j] != NULL)
		{
			fg = 0;
			for (i = 0; arg[j][i] != '\0'; i++)
			{
				if (arg[j][i] == '=') /*(if '=' is found either edit or add to array)*/
				{
					_alias_modify(arg, &name, &value, j, i);
					fg = 1;
					break;
				}
			}
			if (!fg) /* if '=' not found */
				print_alias(arg[j], &name, &value);
			j++;
		}
	}
	return (0);
}
