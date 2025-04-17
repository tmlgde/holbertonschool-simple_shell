#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ligne_texte(char *ligne)
{
	char *token_mot;
	char **token_mots;
	int i = 0;

	token_mots = malloc(80 * sizeof(char *));
	
	if (token_mots == NULL)
	{
		return (NULL);
	}

	token_mot = strtok(ligne, " ");

	while (token_mot != NULL)
	{
		token_mots[i] = strdup(token_mot);
		i++;
		token_mot = strtok(NULL, " ");
	}

	token_mots[i] = NULL;
	return (token_mots);
}
