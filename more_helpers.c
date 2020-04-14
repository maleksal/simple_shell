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
