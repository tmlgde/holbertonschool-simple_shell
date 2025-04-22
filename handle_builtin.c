#include "main.h"

/**
 * handle_builtin - Function that handles built-in commands
 * like 'exit' and 'env'
 * @tokens: The input command as an array of strings
 *
 * Return: 1 if a built-in was handled, 0 otherwise
 */
int handle_builtin(char **tokens)
{
	int i;

	if (!tokens || !tokens[0])
		return (0);

	if (strcmp(tokens[0], "exit") == 0)
	{
		free_tokens(tokens);
		exit(0);
	}

	if (strcmp(tokens[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
		fflush(stdout);
		free_tokens(tokens);
		return (1);
	}
	return (0);
}
