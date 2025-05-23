#include "main.h"
/**
 * main - Programm that interprets a command line
 * as a simple shell.
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, -1 if it failed
 */
int main(int ac, char **av)
{
	char *line = NULL, *command_path;
	size_t len = 0;
	char **tokens;
	int ret; /*ret for return*/
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");/*Handle Ctrl+D (EOF)*/
			break;
		}
		tokens = split_line(line, " \n");
		if (!tokens || !tokens[0])
		{
			free_tokens(tokens);
			continue;
		}
		ret = handle_builtin(tokens);
		if (ret == -1)
			break;
		if (ret == 1)
			continue;
		command_path = find_command_path(tokens[0]);
		if (command_path)
		{
			execve_command(command_path, tokens, environ);
			free(command_path);
		}
		else
			fprintf(stderr, "%s: 1: %s: command not found\n", av[0], tokens[0]);
		free_tokens(tokens);
	}
	free(line);
	return (0);
}
