#include <stdio.h>
#include <sys/stat.h>
#include "main.h"

int main (void)
{
	char *path[] = getenv("PATH");
	/*char *copy = strdup(path);*/
	char *line = NULL;
	int len = 0;
	char **tokens = split_line(copy, ":");
	char *token;
	struct stat st;

	while (tokens != NULL)
	{
		token = getline(&line, &len, stdin);











	}






	return (0);
}
