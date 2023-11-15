#include "tshell.h"

void tprintf(const char *text)
	{
		write(STDOUT_FILENO, text, strlen(text));
	}
