#include "shell.h"
/**
 * check_file_access - A  function that checks if an executabke file exists
 * @filepath: path to file
 * @statbuff: stores information of the file if it exists
 * Return: On success (true), it returns true. On failure, it returns false.
 */
bool check_file_access(char *filepath, struct stat  *statbuff)
{
	int access_status;

	access_status = stat(filepath, statbuff);
	if (access_status == 0)
		return (true);
	return (false);
}

