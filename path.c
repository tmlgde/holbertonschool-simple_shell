#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - Prints all directories listed in the PATH environment variable
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		printf("La variable PATH n'existe pas.\n");
		return (1);
	}

	else
		printf("La valeur complete de PATH est:\n%s\n\n", path);

	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
		printf("copie echouee\n");
		return (1);
	}

	char *directories = strtok(path_copy, ":");

	while (directories != NULL)
	{
		printf("- %s\n", directories);
		directories = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}
