#include "shell.h"

/**
 * _getenv - get enviroment variable by name
 * @name: name of the variable
 * @env: double pointer array contains env variables
 * Return: value of variable
 */

char *_getenv(char *name, char **env)
{

	char *mem_pt;
	int ptr_i = 0, idx;
	int validate = 0;
	int len_name = 0;

	len_name = _strlen(name);

	for ( ; env[ptr_i] != NULL; ptr_i++)
	{
		for (idx = 0; idx < len_name; idx++)
		{
			if (env[ptr_i][idx] == name[idx])
				validate += 1;
		}
		if (validate  == len_name)
			break;
		validate = 0;
	}

	/* duplicate array */
	mem_pt = _strdup(env[ptr_i]);
	if (!mem_pt)
		return (NULL);

	return (mem_pt);
}

/**
 * checkCMDpath - check if cmd exists a list of path
 * belongs to $PATH var
 * @cmd: pointer to string
 * @path: points to array  contains "path:path:path"
 * Return: void
 */

char *checkCMDpath(char *cmd, char *path)
{
	char *full_path;
	char *token;

	int len_cmd;

	struct stat sh;

	/* remove VAR= */
	token = strtok(path, "=");

	token = strtok(NULL, ":");
	len_cmd = _strlen(cmd);

	while (token)
	{
		/* locate space for current token */
		full_path = malloc((_strlen(token) + len_cmd) * sizeof(char) + 2);
		if (!full_path)
			return (NULL);

		/* copy token to full_path & and add /<cmd> */

		_strncpy(full_path, token, 1);

		if (stat(_strcat(full_path, cmd), &sh) == 0)
			return (full_path);

		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
