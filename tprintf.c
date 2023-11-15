#include "tshell.h"

/**
 * tprintf - is my own print function
 * prints text to stdout
 */
void tprintf(const char *text)
	{
		write(STDOUT_FILENO, text, strlen(text));
	}
