#include "tshell.h"

/**
 * _mycurrenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _mycurrenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _tgetenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @envname: env var name
 *
 * Return: the value
 */
char *_tgetenv(info_t *info, const char *envname)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenvt - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenvt(info_t *info)
{
	if (info->argc != 3)
	{
		_tputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_tsetenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenvt - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenvt(info_t *info)
{
	int n;

	if (info->argc == 1)
	{
		_tputs("Too few arguements.\n");
		return (1);
	}
	for (n = 1; n <= info->argc; n++)
		_tunsetenv(info, info->argv[n]);

	return (0);
}

/**
 * populate_envt_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_envt_list(info_t *info)
{
	list_t *node = NULL;
	size_t n;

	for (n = 0; environ[n]; n++)
		add_node_end(&node, environ[n], 0);
	info->env = node;
	return (0);
}
