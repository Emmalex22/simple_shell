#include "shell.h"
/**
 * handle_getline_error - a function that handles getline errors
 * @read: container that olds what gertline receives
 */
void handle_getline_error(ssize_t read)
{
	if (read == -1)
	{
		if (feof(stdin))
		{
			break;
		}
		perror("Error (getline)");
		exit(EXIT_FAILURE);
	}
}
/**
 * handle_fork_error - gunction that handles fork() error
 * @baby_pid: child process
 */
void handle_fork_error(pid_t baby_pid)
{
	if (babypid == -1)
	{
		perror("Error (fork)");
		exit(EXIT_FAILURE);
	}
}
/**
 * handle_wait_error - function that handles wait() error
 * @wstatus: holds info on wait()
 */
void handle_wait_error(int wstatus)
{
	if (wstatus == -1)
	{
		perror("Error (wait)");
		exit(EXIT_FAILURE);
	}
}
