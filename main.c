#include "shell.h"

#define MAX_BUFSIZE 64
#define DELIM " \t\r\a\n"

/**
  * parser - takes the string buffer created by getline and splits it
  * using strtok. new space will be allocated containg the splited string
  * and must be freed by the user.
  *
  * @buffer: pointer
  * Return: pointer to the newly allocated memory
  */

char **parser(char *buffer)
{
		char **args = NULL;
		char *token;

		int bufsize = MAX_BUFSIZE;
		int c = 0;

		args = malloc(bufsize * sizeof(char *));
		if (args == NULL)
		{
			perror("shell");
		}

		/* handle first token */
		token = strtok(buffer, DELIM);
		if (token == NULL)
		{
			perror("shell");
		}

		while (token != NULL)
		{
			args[c++] = token;

			token = strtok(NULL, DELIM);
		}

		args[c] = NULL;
		return (args);

}

/**
 * executer_process - creates a new child process then executes
 * the given command using execve.
 * @env: enviromnet variables
 * @name: name of the executable ./hsh
 * @exec: number of execution, needed for errors
 * @array: takes an 2d array
 * Return: 0 on success OR 1 on fail
 */

int executer_process(char **array, int *exec, char *name, char **env)
{
	char *ptr_mem = NULL, *ptr_path = NULL;
	pid_t pd, wpid;
	struct stat sh;
	int status;

	(void) wpid;
	pd = fork();
	if (pd < 0)
	{
		perror("Error");
		return (0);
	} else if (pd ==  0)
	{
		if (_strcmp("env", array[0]) == 0)
		{	print_env(env);
			return (0);
		}
		if (stat(array[0], &sh) == 0)
			execve(array[0], array, env);
		else
		{
			/*get $PATH and check for command */
			ptr_path = _getenv("PATH", env);
			ptr_mem = checkCMDpath(array[0], ptr_path);
			if (ptr_mem == NULL)
			{
				build_error(array[0], exec, name);
			} else
				execve(ptr_mem, array, env);
		}
		free(ptr_path);
		free(ptr_mem);
		exit(EXIT_FAILURE);
	}
	while ((wpid = wait(&status)) > 0)
	;
	free(ptr_path);
	free(ptr_mem);
	return (1);
}

/**
  * prompt - takes input from stdin using getline and handels
  * the input if it either spaces or new lines.
  * @exec_status: number of input execution
  * Return: pointer
  */

char *prompt(int *exec_status)
{
	ssize_t ret;
	size_t size = 0;

	char *buffer = NULL;

	write(STDIN_FILENO, "#> ", 3);

	ret = getline(&buffer, &size, stdin);

	if (ret <= 0)
	{
		free(buffer);
		buffer = NULL;
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "\n", 1);

		exit(0);
	}

	/* -1 to remove the counted new line */
	if (_stroc(' ', buffer) == _strlen(buffer) - 1)
	{
		free(buffer);
		buffer = NULL;
		*exec_status += 1;
		return (prompt(exec_status));
	}

	return (buffer);
}

/**
 * main - entry point of the shell program
 * @ac: len of av
 * @av: command line arguments
 * @env: enviroment variables
 * Return: int
 */

int main(int ac, char *av[], char **env)
{
	int status = 1;
	int exec_status = 1;

	char *_buffer = NULL;
	char **ptr;

	(void) ac;

	signal(SIGINT, interrupt);
	while (status)
	{

		_buffer = prompt(&exec_status);

		ptr = parser(_buffer);

		/* handle exit*/
		if (_strcmp("exit", ptr[0]) == 0)
		{
			free(_buffer);
			free(ptr);
			exit(0);
		}

		status = executer_process(ptr, &exec_status, av[0], env);
		exec_status++;
		/* clean */
		free(_buffer);
		_buffer = NULL;
		free(ptr);
	}

	return (0);
}
