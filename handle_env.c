#include "shell.h"
/**
 * p_ssenv - a function that prints the environment variables
 */
void p_ssenv(void)
{
	char **penv;

	for (penv = environ; *penv; penv++)
	{
		write(1, *penv, mystrlen(*penv));
		write(1, "\n", 1);
	}
}

