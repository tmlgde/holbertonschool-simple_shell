#include "main.h"

/**
 * _getenv - Function that retrieves the value
 * of an environment variable.
 * @name: The name of the environment variable to search for.
 *
 * Return: A pointer to a newly allocated string containing the value
 * of the environment variable, or NULL if not found or on failure
*/

char *_getenv(const char *name)
{
	int i;
	char *copy, *token, *value;

	if (name == NULL || environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		copy = strdup(environ[i]);
		if (copy == NULL)
			return (NULL);

		token = strtok(copy, "="); /*To split on the name of the variable*/

		if (token && strcmp(token, name) == 0)
		{
			token = strtok(NULL, ""); /*To retrieve the value*/
			if (token)
			{
				value = strdup(token); /*Duplicate the value before free*/
				free(copy);
				return (value);
			}
		}
		free(copy);
	}
	return (NULL);
}
