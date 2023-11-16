#include "shell.h"
/**
 * free_vec - A function that frees memory allocated to a vector
 * @vector: vector to be freed
 * @length: number of pointers in the vector
 */
void free_vec(char **vector, int length)
{
	int i;

	for (i = 0; i < length; i++)
		free(vector[i]);
	free(vector);
}

