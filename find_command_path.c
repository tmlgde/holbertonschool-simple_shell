#include "main.h"

/**
 * find_command_path - Finds the full path of a command
 * @command: The command name or path
 *
 * Return: A malloc'd string containing the full path if found and executable,
 *         or NULL if not found or not executable
 */
char *find_command_path(char *command)
{
	char *path = NULL, *full_path = NULL;
	char **access_path = NULL;
	size_t len = 0;
	int i = 0;

	/* Test direct : si la commande est un chemin valide (relatif ou absolu) */
	if (access(command, X_OK) == 0)
		return (strdup(command)); /* Pas besoin de chercher dans PATH */

	/* Sinon, chercher dans PATH */
	path = _getenv("PATH");
	if (!path || !command)
		return (NULL);

	access_path = split_line(path, ":");
	free(path);
	if (!access_path)
		return (NULL);

	for (i = 0; access_path[i] != NULL; i++)
	{
		/* +2 = '/' + '\0' */
		len = strlen(access_path[i]) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free_tokens(access_path);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", access_path[i], command);

		if (access(full_path, X_OK) == 0)
		{
			free_tokens(access_path);
			return (full_path); /* ✅ Fichier trouvé et exécutable */
		}

		free(full_path);
		full_path = NULL;
	}

	free_tokens(access_path);
	return (NULL); /* ❌ Rien trouvé */
}

