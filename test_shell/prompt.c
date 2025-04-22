#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ "); /*Affiche le prompt*/
	fflush(stdout); /*S'assure que le $ s'affiche tout de suite*/
	
	read = getline(&line, &len, stdin); /*Lit une ligne depuis l'entrée standard*/
	
	if (read != -1)
		printf("%s", line); /*Affiche ce que l'utilisateur a tapé*/
	else
		perror("error");
	
	free(line);
	return (0);
}
