#include "shell.h"

/**
  * _strlen - get length of a string
  * @str: pointer to a string
  * Return: len of string execluding null byte \0
  */

int _strlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
	;

	return (len);
}

/**
  * _strncpy - copies a string
  * @dest: destination
  * @src: source
  * @status: if 1 add '/' to dest
  * Return: pointer to dest
  */

char *_strncpy(char *dest, char *src, int status)
{
	int index;

	for (index = 0; src[index] != '\0'; index++)
	{
		dest[index] = src[index];
	}

	if (status == 1)
		dest[index++] = '/';

	dest[index] = '\0';

	return (dest);
}

/**
  * _strcmp - compare two strings
  * @s1: type int
  * @s2: type int
  * Return: 0 if string match, less than 0 or greater if they dont match
  */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int len_s2 = _strlen(s2);

	while (s1[i] != '\0')
	{
		if (len_s2 < i && s1[i] !=  s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}


/**
  * _strcat - concatenates two strings
  * @dest: pointer to destination
  * @src: pointer to source
  * Return: pointer to destination
  */

char *_strcat(char *dest, char *src)
{
	int index;
	int dest_last_elem = 0;

	while (dest[dest_last_elem] != '\0')
	{
		dest_last_elem++;
	}

	for (index = 0; src[index] != '\0'; index++, dest_last_elem++)
	{
		dest[dest_last_elem] = src[index];
	}

	dest[dest_last_elem] = '\0';
	return (dest);
}

/**
 * _strdup - duplicates an array to a newly located memory using
 * malloc, located memory must be freed by the user program.
 * @array: pointer to char
 * Return: pointer to the duplicated array
 */

char *_strdup(char *array)
{
	int elements;
	int idx = 0;
	char *_mem;

	/* count elements */
	elements = _strlen(array);

	/* locate space && check for failure */
	_mem = malloc(elements * sizeof(char) + 1);
	if (!_mem)
		return (NULL);

	for ( ; array[idx] != '\0'; idx++)
		_mem[idx] = array[idx];

	_mem[idx] = '\0';

	return (_mem);
}
