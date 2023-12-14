#include "shell.h"

/**
 * mygetenv - Get the value of an environment variable
 * @pair: Name of the environment variable
 * Return: Pointer to the value or NULL if not found
 */
char *mygetenv(const char *pair)
{
	char **p;
	char *token;
	size_t len = mystrlen(pair);

	for (p = environ; *p; p++)
	{
		token = strtok(*p, "=");
		if (token && (size_t)mystrlen(token) == len && mystrcmp(token, pair) == 0)
		{
			return (strtok(NULL, "="));
		}
	}

	return (NULL);
}
