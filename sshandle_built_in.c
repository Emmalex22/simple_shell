#include "shell.h"

/**
 * handle_built_in - a function that implements built-in commands
 * @usercmd: user command to execute
 */
void handle_built_in(char *usercmd)
{
	if (mystrcmp(usercmd, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (mystrcmp(usercmd, "env") == 0)
	{
		p_ssenv();
	}
}

