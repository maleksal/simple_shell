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
 * the give command using execve.
 *
 * @array: takes an 2d array
 * Return: 0 on success OR 1 on fail
 */

int executer_process(char **array)
{
	char *ptr_mem = NULL;
	char *ptr_path = NULL;
	pid_t pd, wpid;
	struct stat sh;
	int status;

	pd = fork();
	if (pd < 0)
	{
		perror("shell");
		return (0);
	}

	else if (pd ==  0)
	{
		
		if (stat(array[0], &sh) == 0)
			execve(array[0], array, environ);
		
		else
		{

			/*get $PATH and check for command */
			
			ptr_path = _getenv("PATH", environ);
			ptr_mem = checkCMDpath(array[0], ptr_path);

			if (ptr_mem == NULL)
				execve(array[0], array, environ);
			else
				execve(ptr_mem, array, environ);
		}

		perror(array[0]);
	}

	while ((wpid = wait(&status)) > 0)
	;
	
	free(ptr_path);
	free(NULL);

	return (1);
}

/**
  * prompt - takes input from stdin using getline
  * Return: pointer
  */

char *prompt(void)
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
		return (prompt());
	}

	return (buffer);
}

/**
 * main - entry point of the shell program
 * Return: int
 */

int main(void)
{
	int status = 1;

	char *_buffer = NULL;
	char **ptr;

	while (status)
	{

		_buffer = prompt();

		ptr = parser(_buffer);
		status = executer_process(ptr);

		/* clean */
		free(_buffer);
		_buffer = NULL;
		free(ptr);

	}

	return (0);
}
