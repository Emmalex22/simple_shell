#include "shell.h"
/**
 * main - entry point
 * Return: always 0
 */
int main(void)
{
	char *usercmd;
	bool via_pipe = false;

	while (1 && !via_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			via_pipe = true;
		prompt();
		read_n_parse_input();
		handle_path(usercmd);
		handle_built_in(usercmd);
	}
	return (0);
}
