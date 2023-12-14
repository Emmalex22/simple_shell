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
	char *token = NULL;
	char **paths = NULL;
	char *total_path = NULL;
	size_t x, no_of_paths = 0;

	if (present_path == NULL || filename == NULL)
	{
		return (NULL);
	}
	token = strtok(present_path, ":");
	while (token != NULL)
	{
		paths = realloc(paths, (no_of_paths + 1) * sizeof(*paths));
		if (paths == NULL)
		{
			return (NULL);
		}
		paths[no_of_paths] = mystrdup(token);
		if (paths[no_of_paths] == NULL)
		{
			while (no_of_paths > 0)
			{
				free(paths[--no_of_paths]);
			}
			free(paths);
			return (NULL);
		}
		no_of_paths++;
		token = strtok(NULL, ":");
	}
	if (no_of_paths == 0)
	{
		free(paths);
		return (NULL);
	}

	for (x = 0; x < no_of_paths; x++)
	{
		total_path = mystrcat(3, paths[x], "/", filename);
		if (total_path == NULL)
		{
			while (no_of_paths > 0)
			{
				free(paths[--no_of_paths]);
			}
			free(paths);
			return (NULL);
		}
		if (check_file_access(total_path, statbuff))
		{
			while (no_of_paths > 0)
			{
				free(paths[--no_of_paths]);
			}
			free(paths);
			return (total_path);
		}
		free(total_path);
	}

	while (no_of_paths > 0)
	{
		free(paths[--no_of_paths]);
	}
	free(paths);
	return (NULL);
}

