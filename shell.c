#include "shell.h"
/**
 * main - entry point
 * @argc: arguement count
 * @argv: arguement vector
 * Return: always 0
 */
int main(void)
{
	bool via_pipe = false;
	char *input, *args, *buffer = NULL;
	struct stat statbuff;
	pid_t baby_pid;
	int wstatus;
	char **env = environ;

	while (1 && !via_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			via_pipe = true;
		prompt();
		input = read_n_parse_input();
		if (input == NULL)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (handle_built_in(input) == 0)
		{
			free(input);
			continue;
		}
		baby_pid = fork();
		if (baby_pid == -1)
			handle_fork_error(baby_pid);
		if (baby_pid == 0)
		{
			if (ssexecutor(buffer, &statbuff, env) == -1)
			{
				perror("Error (execve)");
				exit(EXIT_FAILURE);
			}
			args = strtok(buffer, " ");
			handle_path(args);
			exit(EXIT_SUCCESS);
		}
		if (waitpid(baby_pid, &wstatus, 0) == -1)
			handle_wait_error(wstatus);
	}
	free(buffer);
	return (0);
}
