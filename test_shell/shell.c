#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

int main(void)
{
	char *line = NULL, *argv[2];
	char **tokens;
	size_t len = 0;
        ssize_t read;
        pid_t child_pid;
        int status;
	extern char **environ /*Tableau global contenant les variables d’environnement*/;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		read = getline(&line, &len, stdin);

		if (read != -1)
		{
			tokens = split_line(line, " \n");
			/*tokens[0][strcspn(tokens[0], "\n")] = '\0';*/
			/*Remplace le caractère \n à la fin de tokens[0] par un caractère nul \0, ce qui enlève le retour à la ligne.*/

			if (tokens == NULL || tokens[1] != NULL)
			{
				perror("Error:");
			}

                	argv[0] = tokens[0];
                	argv[1] = NULL;

			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
			}

			if (child_pid == 0) 
			{
				if (execve(argv[0], argv, environ) == -1)
					perror("Error:");
			}
			else
				wait(&status);
		}
	}
	free(line);
	return (0);
}
