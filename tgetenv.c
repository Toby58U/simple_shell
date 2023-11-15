#include "tshell.h"

/**
 * tget_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **tget_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _tunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @svar: the string env var property
 */
int _tunsetenv(info_t *info, char *svar)
{
	list_t *node = info->env;
	size_t n = 0;
	char *p;

	if (!node || !svar)
		return (0);

	while (node)
	{
		p = starts_with(node->string, svar);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), n);
			n = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		n++;
	}
	return (info->env_changed);
}

/**
 * _tsetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @svar: the string env var property
 * @svalue: the string env var value
 *  Return: Always 0
 */
int _tsetenv(info_t *info, char *svar, char *svalue)
{
	char *buff = NULL;
	list_t *node;
	char *p;

	if (!svar || !svalue)
		return (0);

	buff = malloc(_strlen(svar) + _strlen(svalue) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, svar);
	_strcat(buff, "=");
	_strcat(buff, svalue);
	node = info->env;
	while (node)
	{
		p = starts_with(node->string, svar);
		if (p && *p == '=')
		{
			free(node->string);
			node->string = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
