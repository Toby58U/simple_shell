#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* printers.c */
int _tputsfd(char *string, int fd);
int _tputfd(char x, int fd);
int _tputchar(char x);
void _tputs(char *string);

#endif
