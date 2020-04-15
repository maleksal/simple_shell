#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int _strlen(char *);
char *_strncpy(char *, char *, int);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);
int _stroc(char, char *);
char *_getenv(char *name, char **env);
char *checkCMDpath(char *cmd, char *path);
void build_error(char *, int *, char*);

#endif
