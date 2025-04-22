#include "main.h"

/**
 * split_line - Splits a string into tokens using a delimiter
 * @str: The input string to split
 * @delim: The delimiter (e.g. " ", ":\n")
 *
 * Return: A NULL-terminated array of tokens (each is strdup'd), or NULL on failure
 */
char **split_line(const char *str, const char *delim)
{
	size_t token_size = 10, count = 0;
	char **tokens = NULL, **temp_tokens = NULL;
	char *copy = NULL, *token = NULL;

	if (str == NULL)
		return (NULL);

	copy = strdup(str);
	if (copy == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * token_size);
	if (tokens == NULL)
	{
		free(copy);
		return (NULL);
	}

	token = strtok(copy, delim);
	while (token != NULL)
	{
		if (count == token_size)
		{
			token_size *= 2;
			temp_tokens = realloc(tokens, sizeof(char *) * token_size);
			if (temp_tokens == NULL)
			{
				free_tokens(tokens);
				free(copy);
				return (NULL);
			}
			tokens = temp_tokens;
		}

		tokens[count] = strdup(token);
		if (tokens[count] == NULL)
		{
			free_tokens(tokens);
			free(copy);
			return (NULL);
		}

		count++;
		token = strtok(NULL, delim);
	}

	tokens[count] = NULL;
	free(copy);
	return (tokens);
}

