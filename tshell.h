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

/* ttokenize.c */
char **strtowrd(char *string, char *d);
char **strtowrdii(char *string, char d);

/* tgetenv.c */
char **tget_environ(info_t *info);
int _tunsetenv(info_t *info, char *svar);
int _tsetenv(info_t *info, char *svar, char *svalue);

/* tgetinfo.c */
void tclear_info(info_t *info);
void tset_info(info_t *info, char **av);
void tfree_info(info_t *info, int all);

/* tenviron.c */
int _mycurrenv(info_t *info);
char *_tgetenv(info_t *info, const char *envname);
int _mysetenvt(info_t *info);
int _myunsetenvt(info_t *info);
int populate_envt_list(info_t *info);

/* tstring.c */
char *_strcat(char *destbuff, char *srcbuff);
char *starts_with(const char *haystack, const char *needle);
int _strcmp(char *z1, char *z2);
int _strlen(char *z);

/* 1-tstring.c */
char *_strcpy(char *destn, char *srce);
char *_strdup(const char *string);
int _putchar(char x);
void _puts(char *string);

/* tshell_loop.c */
int hsh(info_t *info, char **av);
int find_builtin(info_t *info);
void find_cmnd(info_t *info);
void fork_cmnd(info_t *info);

#endif
