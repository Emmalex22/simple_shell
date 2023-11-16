#include "shell.c"
/**
 * prompt - a function that prints a prompt to the screen
 * Return: prompt
 */
const char prompt(void)
{
	const char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, 2);
	return (prompt);
}

