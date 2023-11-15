#include "tshell.h"

/**
 *_tputs - prints an input string
 * @string: the string to be printed
 *
 * Return: Nothing
 */
void _tputs(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_tputchar(string[i]);
		i++;
	}
}

/**
 * _tputchar - writes the character x to stderr
 * @x: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _tputchar(char x)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 * _tputfd - writes the character x to given fd
 * @x: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _tputfd(char x, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 *_tputsfd - prints an input string
 * @string: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _tputsfd(char *string, int fd)
{
	int i = 0;

	if (!string)
		return (0);
	while (*string)
	{
		i += _tputfd(*string++, fd);
	}
	return (i);
}
