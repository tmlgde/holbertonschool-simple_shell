#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *line;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	fflush(stdout);

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		perror("getline");
		free(line);
		return (1);
	}

	printf("%s\n", line);
	free(line);
	return (0);
}

