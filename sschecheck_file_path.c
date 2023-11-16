#include "shell.h"
/**
 * check_file_path - checks if file exist in PATH
 * @statbuff: stores info on the file if found
 * @filename: Name of file to search for in PATH
 * Return:  full_path or Null if not found
 */
char *check_file_path(const char *filename, struct stat *statbuff)
{
	char *present_path = mygetenv("PATH");
	char *total_path;
	size_t no_of_paths, x;
	char **paths = strtok(present_path, ":", &no_of_paths);

	if (present_path == NULL || filename == NULL)
		return (NULL);
	if (paths == NULL || no_of_paths == 0)
		return (NULL);
	for (x = 0; x < no_of_paths; x++)
	{
		total_path = mystrcat(3, paths[x], "/", filename);
		if (total_path == NULL)
		{
			free_vec(paths, no_of_paths);
			return (NULL);
		}
		if (check_file_access(total_path, statbuff))
		{
			free_vec(paths, no_of_paths);
			return (total_path);
		}
		free(total_path);
	}
	free_vec(paths, no_of paths);
	return (NULL);
}

