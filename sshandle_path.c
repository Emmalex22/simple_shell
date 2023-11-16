#include "shell.h"
/**
 * handle_path - function that implements PATH
 * @usercmd: user input command
 */
void handle_path(char *usercmd)
{
	char *buffer = mystrdup(usercmd);
	char *arg;
	char **env;
	char *fullpath;

	if (buffer == NULL)
	{
		perror("Error (mystrdup)");
		return;
	}

	arg = strtok(buffer, " ");

	while (arg != NULL)
	{
		if (check_file_access(arg, &statbuff))
		{
			fullpath = check_file_path(arg, &statbuff);
			if (fullpath != NULL)
			{
				free(arg);
				arg = fullpath;
				ssexecutor(arg, &statbuff, env);
			}
			else
			{
				perror("Error (file access)");
				free(buffer);
				return;
			}
		}
		arg = strtok(NULL, " ");
	}

	free(buffer);
}

