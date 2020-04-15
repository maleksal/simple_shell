#include "shell.h"

/**
 * _stroc - count occurens of char in a string
 * @ch: character
 * @src: string
 * Return: count of occurences
 */

int _stroc(char ch, char *src)
{
	int count = 0;
	int idx = 0;

	for ( ; src[idx] != '\0'; idx++)
	{
		if (src[idx] == ch)
			count++;
	}

	return (count);

}

/**
 * put_stderr - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int put_stderr(char c)
{
	return (write(2, &c, 1));
}


/**
  *  print_number - print digits
  *  ------------------
  *
  *  @n: takes an int (digit)
  *
  *  Return: implicit return
 **/

void print_number(int n)
{
	if (n / 10 != 0)
	{
		print_number(n / 10);
		if (n > 0)
		{
			put_stderr((n % 10) + '0');
		} else
		{
			put_stderr((-n % 10) + '0');
		}
	}
	else if ((n / 10 == 0) && (n % 10 != 0) && (n > 0))
	{
		put_stderr((n % 10) + '0');
	}
	else if ((n / 10 == 0) && (n % 10 != 0) && (n <= 0))
	{
		put_stderr('-');
		put_stderr((-n % 10) + '0');
	}
}


/**
 * build_error - builds an error when command not found
 * @program_name: name of exec ./hsh
 * @str: cmmand name
 * @status: number of executions
 */


void build_error(char *str, int *status, char *program_name)
{
	int len = _strlen(str);
	int len2 = _strlen(program_name);
	char notfound[] = ": not found\n";

	write(2, program_name, len2);
	write(2, ": ", 2);
	print_number(*status);
	write(2, ": ", 2);
	write(2, str, len);
	write(2, &notfound, _strlen(notfound));
}

/**
* print_env - print enviroments variables at the presense of command env
* @env: evniroment variables
*/

void print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
}
