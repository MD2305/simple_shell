#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * new_alias - generate two strings of new data
 * @arg: the array of tokens
 * @s1: the index of arg[x] where '=' was found
 * @s2: the index of the string of arg
 *
 * Return: Nothing.
 */
alias_list *new_alias(char **arg, int s1, int s2)
{
	alias_list *a = NULL;
	int T, i = 0, j, k;

	while (arg[i] != NULL)
		i++;
	a = malloc(sizeof(alias_list));
	if (a == NULL)
		return (NULL);
	a->name = malloc(sizeof(char) * s2 + 1);
	if (a->name == NULL)
	{
		free(a);
		return (NULL);
	}
	a->name = strncpy(a->name, arg[s1], s2);
	a->name[s2] = '\0';
	a->value = malloc(sizeof(char) * 100);
	if (a->value == NULL)
	{
		free(a->name), free(a);
		return (NULL);
	}
	k = 0;
	for (T = s1, j = s2 + 1, k = 0; arg[T][j] != '\0'; j++, k++)
	{
		a->value[k] = arg[T][j];
	}
	a->value[k] = '\0';
	return (a);
}
/**
 * _alias_modify - modifie the list of alias
 * @arg: the array of tokens
 * @name: a pointer to the array of names
 * @value: a pointer to the array of values
 * @s1: the index of arg[x] where '=' was found
 * @s2: the index of the arg to look in
 *
 * Return: -1 in failure, 1 in success.
 */
int _alias_modify(char **arg, char ***name, char ***value, int s1, int s2)
{
	int i;
	alias_list *a = NULL;

	a = new_alias(arg, s1, s2);
	if (a == NULL)
		return (-1);
	for (i = 0; (*name)[i] != NULL; i++)
	{
		if (strcmp((*name)[i], a->name) == 0)
		{
			free((*value)[i]);
			free(a->name);
			(*value)[i] = a->value;
			free(a);
			return (0);
		}
	}
	*name = (char **)realloc(*name, sizeof(char *) * (i + 2));
	if (*name == NULL)
		return (-1);
	*value = (char **)realloc(*value, sizeof(char *) * (i + 2));
	if (*value == NULL)
		return (-1);
	(*name)[i] = a->name;
	(*name)[i + 1] = NULL;
	(*value)[i] = a->value;
	(*value)[i + 1] = NULL;
	free(a);
	return (0);
}

