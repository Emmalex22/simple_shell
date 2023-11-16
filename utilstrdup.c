#include "shell.h"

/**
 * mystrdup - function that duplicates string
 * @str: string to duplicate
 * Return: duplicated string
 */
char *mystrdup(const char *str)
{
	size_t len;
	char *dest;

	if (str == NULL)
		return (NULL);

	len = mystrlen(str);
	dest = (char *)malloc((len + 1) * sizeof(char));

	if (dest == NULL)
	{
		perror("Error (malloc)");
		return (NULL);
	}

	mystrcpy(dest, str, len + 1);
	return (dest);
}

