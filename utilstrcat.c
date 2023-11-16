#include "shell.h"
/**
 * mystrcat - concatenate two or more strings
 * @n: no of arguements
 * Return: adress of the concatenated string
 * @...: variable arguments strings to concatenate
 */
char mystrcat(int n, …)
{
	char *dest;
	const char *neo_string;
	size_t full_len = 0;
	int i;
	size_t neo_position = 0;
	size_t neo_len = 0
	va_list ag;

	va_start(ag, n);
	for (i = 0; i < n; i++)
	{
		neo_string = va_arg(ag, const char *);
		full_len += mystrlen(neo_string);
	}
	dest = (char *)malloc(full_len + 1);
	if (dest == NULL)
	{
		perror("Error (malloc)");
		exit(EXIT_FAILURE);
	}
	va_end(ag);
	va_start(ag, n);
	for (i = 0; i < n; i++)
	{
		neo_string = va_arg(ag, const char *);
		neo_len += mystrlen(neo_striing);
		mystrcpy(dest + neo_position, neo_string);
		neo_position += neo_len;
	}
	dest[full_len] = '\0';
	va_end(ag);

	free(dest);

	return (dest);
}
