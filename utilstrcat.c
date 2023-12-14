#include "shell.h"

char *mystrcat(int n, ...)
{
	char *dest;
	const char *neo_string;
	size_t full_len = 0;
	size_t remaining_space;
	size_t copy_length;
	int i;
	size_t neo_len = 0;
	va_list ag;

	va_start(ag, n);
	for (i = 0; i < n; i++)
	{
		neo_string = va_arg(ag, const char *);
		full_len += mystrlen(neo_string);
	}
	va_end(ag);

	dest = (char *)malloc(full_len + 1);
	if (dest == NULL)
	{
		perror("Error (malloc)");
		exit(EXIT_FAILURE);
	}

	dest[0] = '\0';

	remaining_space = full_len;

	va_start(ag, n);
	for (i = 0; i < n; i++)
	{
		neo_string = va_arg(ag, const char *);
		neo_len = mystrlen(neo_string);
		copy_length = (remaining_space < neo_len) ? remaining_space : neo_len;
		mystrcpy(dest + full_len - remaining_space, neo_string, copy_length);
		remaining_space -= copy_length;
	}
	va_end(ag);
	dest[full_len] = '\0';
	return (dest);
}
