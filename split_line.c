#include "main.h"
/**
 * split_line - Function that splits a string
 * and returns an array of each word of the string
 * @str: string to split
 * @delim: delimitator
 *
 * Return: an array of each word of the string
 */
char **split_line(const char *str, const char *delim)
{
	size_t token_size = 10;
	size_t count = 0;
	char **tokens = malloc(sizeof(char *) * token_size);
	char **temp_tokens;
	char *token;
	char *copy = strdup(str); /*Copie modifiable de la chaîne d'origine*/

	if (tokens == NULL || copy == NULL || str == NULL)
		return (NULL);

	token = strtok(copy, delim);
	while (token != NULL)
	{
		if (count == token_size)
		{
			token_size *= 2;
			temp_tokens = realloc(tokens, sizeof(char *) * token_size);
			if (temp_tokens == NULL)
			{
				free(copy);
				return (NULL);
			}
			tokens = temp_tokens;
		}
		tokens[count] = strdup(token);
		count++;
		token = strtok(NULL, delim);
	}

	tokens[count] = NULL;
	free(copy);
	return (tokens);
}
