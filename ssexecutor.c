#include "shell.h"
/**
 * ssexecutor - A function that executes shell commands
 * @usercmd: command entered by the user
 * @env: enviroment variable
 * @statbuff: a buffer that holds info about the file to be executed
 */
void ssexecutor(char *usercmd, struct stat *statbuff, char **env)
{
	int ac;
	char **token;

	token = strtok(usercmd, " ", &ac);
	if (token == NULL)
	{
		perror("Error (strtok)");
		exit(EXIT_FAILURE);
	}
	/*****check if executable file exists***/
	if (!check_file_access(token[0], statbuff)
	{
		perror("Error (file access)");
		exit(EXIT_FAILURE);
	}
			/***Check if exec fails****/
	if (execve(token[0], token, env) == -1)
	{
		perror("Error (execve)");
		exit(EXIT_FAILURE);
	}
	free_vec(token, 30);
}
