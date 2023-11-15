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

/* 1-printers.c */
int _tstrtoint(char *z);
void tprint_err(info_t *info, char *errstr);
int tprint_dec(int input, int fd);
char *convert_num(long int numb, int base, int flags);
void rm_comments(char *buff);

/* tgetline.c */
ssize_t tget_input(info_t *info);
ssize_t tinput_buff(info_t *info, char **buff, size_t *lent);
ssize_t tread_buf(info_t *info, char *buff, size_t *n);
int _tgetline(info_t *info, char **pntr, size_t *length);
void siginthandler(__attribute__((unused))int sig_numb);

#endif
