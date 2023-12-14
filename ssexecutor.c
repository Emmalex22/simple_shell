#include "shell.h"
/**
 * ssexecutor - A function that executes shell commands
 * @usercmd: command entered by the user
 * @env: enviroment variable
 * @statbuff: a buffer that holds info about the file to be executed
 */
int ssexecutor(char *usercmd, struct stat *statbuff, char **env)
{
	char *cmd_copy;
	char *token;

	cmd_copy = mystrdup(usercmd);
	token = strtok(cmd_copy, " ");
	if (token == NULL)
	{
		perror("Error (strtok)");
		free(cmd_copy);
		exit(EXIT_FAILURE);
	}
	if (!check_file_access(token, statbuff))
	{
		perror("Error (file access)");
		free(cmd_copy);
		exit(EXIT_FAILURE);
	}
	if (execve(token, &token, env) == -1)
	{
		perror("Error (execve)");
		free(cmd_copy);
		exit(EXIT_FAILURE);
	}
	free(cmd_copy);
	return (0);
}
