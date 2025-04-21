#include "main.h"
/**
 * main - Programm that interprets a command line
 * as a simple shell.
 *
 * Return: 0 on success, -1 if it failed
 */
int main(void)
{
	char *line = NULL, *command_path;
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
		if (!tokens || !tokens[0])
		{
			free_tokens(tokens);
			continue;
		}
		/*Checks if the command is a valid path to an executable*/
		if (access(tokens[0], X_OK) == 0)
			execve_command(tokens[0], tokens, environ);
		else
		{	/*Otherwise search in the PATH*/
			command_path = find_command_path(tokens[0]);
			if (command_path)
			{
				execve_command(command_path, tokens, environ);
				free(command_path);
			}
			else
				fprintf(stderr, "%s: command not found\n", tokens[0]);
		free_tokens(tokens);
		}
	}
	free(line);
	return (0);
}
