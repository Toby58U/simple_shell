#include "tshell.h"

/**
 * _strcpy - copies a string
 * @destn: the destination
 * @srce: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *destn, char *srce)
{
	int n = 0;

	if (destn == srce || srce == 0)
		return (destn);
	while (srce[n])
	{
		destn[n] = srce[n];
		n++;
	}
	destn[n] = 0;
	return (destn);
}

/**
 * _strdup - duplicates a string
 * @string: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *string)
{
	int length = 0;
	char *ret;

	if (string == NULL)
		return (NULL);
	while (*string++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@string: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *string)
{
	int n = 0;

	if (!string)
		return;
	while (string[n] != '\0')
	{
		_putchar(string[n]);
		n++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @x: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char x)
{
	static int n;
	static char buff[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(1, buff, i);
		n = 0;
	}
	if (x != BUF_FLUSH)
		buff[n++] = x;
	return (1);
}
