#include "main.h"
/**
 * mystrcpy - copy a string up to 'n' characters
 * @dest: destination to copy to
 * @src: source to copy from
 * @n: number of characters to copy
 * Return: pointer to the destination string
 */
char mystrcpy(char *dest, const char *src, size_t n)
{
	size_t j;

	if (src == NULL || dest == NULL || n == 0)
		return (NULL);
	for (j = 0; j < n - 1 && src[j] != '\0'; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';
	return (dest);
	}
}
