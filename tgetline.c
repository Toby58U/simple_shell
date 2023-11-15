#include "tshell.h"

/**
 * tinput_buff - buffers chained commands
 * @info: parameter struct
 * @buff: address of buffer
 * @lent: address of len var
 *
 * Return: bytes read
 */
ssize_t tinput_buff(info_t *info, char **buff, size_t *lent)
{
	ssize_t b = 0;
	size_t len_p = 0;

	if (!*lent) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		b = getline(buff, &len_p, stdin);
#else
		b = _getline(info, buff, &len_p);
#endif
		if (b > 0)
		{
			if ((*buff)[b - 1] == '\n')
			{
				(*buff)[b - 1] = '\0'; /* remove trailing newline */
				b--;
			}
			info->linecount_flag = 1;
			rm_comments(*buff);
			build_hist_list(info, *buff, info->histcount++);
			{
				*lent = b;
				info->cmd_buf = buff;
			}
		}
	}
	return (b);
}

/**
 * tget_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t tget_input(info_t *info)
{
	static char *buff; /* the ';' command chain buffer */
	static size_t i, j, lent;
	ssize_t b = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	b = tinput_buff(info, &buff, &lent);
	if (b == -1) /* EOF */
		return (-1);
	if (lent)	/* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buff + i; /* get pointer for return */

		check_chain(info, buff, &j, i, lent);
		while (j < lent) /* iterate to semicolon or end */
		{
			if (is_chain(info, buff, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= lent) /* reached end of buffer? */
		{
			i = lent = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buff; /* else not a chain, pass back buffer from _getline() */
	return (b); /* return length of buffer from _getline() */
}

/**
 * tread_buf - reads a buffer
 * @info: parameter struct
 * @buff: buffer
 * @n: size
 *
 * Return: b
 */
ssize_t tread_buf(info_t *info, char *buff, size_t *n)
{
	ssize_t b = 0;

	if (*n)
		return (0);
	b = read(info->readfd, buff, READ_BUF_SIZE);
	if (b >= 0)
		*n = b;
	return (b);
}

/**
 * _tgetline - gets the next line of input from STDIN
 * @info: parameter struct
 * @pntr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: z
 */
int _tgetline(info_t *info, char **pntr, size_t *length)
{
	static char buff[READ_BUF_SIZE];
	static size_t n, lent;
	size_t k;
	ssize_t b = 0, z = 0;
	char *p = NULL, *new_p = NULL, *x;

	p = *pntr;
	if (p && length)
		z = *length;
	if (n == lent)
		n = lent = 0;

	b = tread_buf(info, buff, &lent);
	if (b == -1 || (b == 0 && lent == 0))
		return (-1);

	x = _strchr(buff + n, '\n');
	k = x ? 1 + (unsigned int)(x - buff) : lent;
	new_p = _realloc(p, z, z ? z + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (z)
		_strncat(new_p, buff + n, k - n);
	else
		_strncpy(new_p, buff + n, k - n + 1);

	z += k - n;
	n = k;
	p = new_p;

	if (length)
		*length = z;
	*pntr = p;
	return (z);
}

/**
 * siginthandler - blocks ctrl-C
 * @sig_numb: the signal number
 *
 * Return: void
 */
void siginthandler(__attribute__((unused))int sig_numb)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
