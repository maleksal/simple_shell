#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>



/**
 * struct builtin - struct for builtin functions
 * @cmd: pointer to arr
 * @ptr_v: pointer to function that takes no param
 * @ptr: pointer to function that takes param
 */

typedef struct builtin
{
	char *cmd;
	void (*ptr_v) (int);
	void (*ptr) (char *);
} b_cmd;


int _strlen(char *);
char *_strncpy(char *, char *, int);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);
int _stroc(char, char *);
char *_getenv(char *name, char **env);
char *checkCMDpath(char *cmd, char *path);

extern char **environ;

#endif
