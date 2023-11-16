#include "shell.h"
/**
 * read_n_parse_input - a function that reads input and parses it
 */
void read_n_parse_input(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t read;
	char *token;
	pid_t baby_pid;
	int ac;
	char **env;
	char *args[MAX_ARGS];
	const char *delim = " ";

	read = getline(&buffer, &buffer_size, stdin);
	if (read == -1)
		handle_getline_error(read);
	if (buffer[read - 1] == '\n')
		buffer[read - 1] = '\0';
	token = strtok(buffer, delim);
		while (token != NULL)
		{
			args[ac++] = token;
			token = strtok(NULL, delim);
		}
	args[ac] = NULL;
	baby_pid = fork();
	if (baby_pid == -1)
	{
		handle_fork_error(pid_t baby_pid);
		free(buffer);
	}
	if (baby_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Error (execve)");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
		wait(NULL);
	free(buffer);
}
