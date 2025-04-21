#include "main.h"
/**
 * main - Programm that interprets a command line
 * as a simple shell.
 *
 * Return: 0 on success, -1 if it failed
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **tokens;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("\n");/*Handle Ctrl+D (EOF)*/
			break;
		}
		/*Replaces the \n character at the end of tokens[0] with \0.*/
		tokens = split_line(line, " \n");
		if (!tokens || !tokens[0] || tokens[1])
		{
			perror("Error execve:");
			free_tokens(tokens);
			continue;
		}
		execve_command(tokens, environ);
		free_tokens(tokens);
	}
	free(line);
	return (0);
}
