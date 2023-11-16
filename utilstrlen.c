#include "shell.h"
/**
 * mystrlen - returns the length of a string
 * @s: string
 * Return: length
 */
int mystrlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}

