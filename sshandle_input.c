#include "shell.h"
/**
 * read_n_parse_input - a function that reads input and parses it
 */
char *read_n_parse_input(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t read;
	char *token;
	const char *delim = " ";

	read = getline(&buffer, &buffer_size, stdin);
	if (read == -1)
		handle_getline_error(read);
	if (buffer[read - 1] == '\n')
		buffer[read - 1] = '\0';
	token = strtok(buffer, delim);
		while (token != NULL)
		{
			token = strtok(NULL, delim);
		}
	free(buffer);
	return (NULL);
}
