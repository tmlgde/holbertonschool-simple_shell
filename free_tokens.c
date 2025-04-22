#include "main.h"

/**
 * free_tokens - Fonction that frees the memory
 * allocated for an array of strings.
 * @tokens: Array of strings to be freed.
 *
 * Return: Nothing
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens)
	{
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
	}
	free(tokens);
}
