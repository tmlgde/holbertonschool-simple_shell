#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
	char *path = getenv("PATH");
	char **tokens = split_line(path, ":");
	int j;
	/*char *line = NULL;
	size_t len = 0;*/
	struct stat st;
	/*ssize_t read = getline(&line, &len, stdin);*/
	/*char *string_1 = strcat(tokens[j], "/");
	char *string_2 = strcat(string_1, av[i]);*/

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	
	for (j = 0; tokens[j] != NULL; j++)
	{
		char *string_1 = strcat(tokens[j], "/");
		char *string_2 = strcat(string_1, av[1]);
		
		if (stat(string_2, &st) == 0)
		{
			printf("%s\n", string_2);
			break;
		}
	}
	return (0);
}
