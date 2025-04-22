#include "main.h"

/**
 * find_command_path - Function that searches for the full path
 * of a command in the PATH variable.
 * @command: The name of the command to search for.
 *
 * Return: A pointer to a newly allocated string containing the full path
 * to the command if found and executable, or NULL if the command
 * is not found or an error occurs.
 */
char *find_command_path(char *command)
{
	char *path = NULL, *full_path = NULL;
	char **access_path = NULL;
	size_t len = 0;
	int i = 0;

	if (access(command, X_OK) == 0) /*command is a valid pass*/
		return (strdup(command)); /*No need to find on the PATH*/

	path = _getenv("PATH");/*Otherwise found in the PATH*/
	if (!path || !command)
		return (NULL);
	access_path = split_line(path, ":");
	free(path); /*Free the PATH copy since it's no longer needed*/
	if (!access_path)
		return (NULL);
	for (i = 0; access_path[i] != NULL; i++)
	{	/*1 for '/' and 1 for '\0'*/
		len = strlen(access_path[i]) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free_tokens(access_path);
			return (NULL);
		}
		/* Creates full_path = access_path[i] + "/" + command */
		sprintf(full_path, "%s/%s", access_path[i], command);
		/* Check if the constructed path is an executable */
		if (access(full_path, X_OK) == 0)
		{
			free_tokens(access_path);
			return (full_path); /*Command found*/
		}
		/* If not found, free the allocated path and try next */
		free(full_path);
		full_path = NULL;
	}
	free_tokens(access_path);
	return (NULL);/*No valid command found in any PATH*/
}
