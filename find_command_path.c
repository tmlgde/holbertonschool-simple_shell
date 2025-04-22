#include "main.h"

/**
 * find_command_path - Function that searches for a command
 * in the directories listed in PATH.
 * @command: The name of the command to find.
 *
 * Return: A pointer to a newly allocated string with the full path to the
 * command if found, or NULL if the command is not found or on failure.
*/
char *find_command_path(char *command)
{
	char *path = _getenv("PATH");
	char **access_path = split_line(path, ":");
	struct stat st;
	int i;
	char *full_path = NULL;
	size_t len = 0;

		if (!access_path || !command)
		return (NULL);

		for (i = 0; access_path[i] != NULL; i++)
		{
		/*1 for '/' and 1 for '\0'*/
		len = strlen(access_path[i]) + strlen(command) + 2;

		full_path = malloc(len * sizeof(char));
		if (!full_path)
		{
			free_tokens(access_path);
			return (NULL);
		}
		/*Copy access_path[i] in full_path*/
		strcpy(full_path, access_path[i]);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (stat(full_path, &st) == 0)
		{
			free_tokens(access_path);
			return (full_path); /*Command found*/
		}
		free(full_path);
		full_path = NULL;
	}
	free_tokens(access_path);
	return (NULL); /*Command not found*/
}
