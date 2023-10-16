#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int append_path(char **av);
void execute_command(char *argv, char **av, char *envp[]);
void parseInput(char *lineptr, char ***av, size_t *nchars, int *num_tokens);
void execmd(char **av, char **envp);
void execute_command(char *argv, char **av, char *envp[]);

char *_getline();
char *pipe_getline();
void flushbuffer(char *buff);


char *_strtok(char *str, const char *delim);
int isdelim(char stringc, const char *delim);
void remdelimiter(char *strc, const char *delim);

char *_strcpy(char *destination, const char *source);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(const char *str, int c);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *dest, const char *src);
size_t _strlen(const char *str);
char *_strdup(const char *str);

#endif
