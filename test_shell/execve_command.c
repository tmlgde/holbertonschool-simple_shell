#include "main.h"

/**
 * execve_command - Fonction that creates a child process
 * to execute a command.
 * @tokens: Array of strings containing the command to execute
 * @environ: Array of strings representing the environment variables
 *
 * Return: nothing
 */

int execve_command(char **tokens, char **environ)
{
	pid_t child_pid;
	int status;
	char *argv[2];

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error fork:");
	}
	if (child_pid == 0)
	{
		argv[0] = tokens[0];
		argv[1] = NULL;
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error exercve:");
		}
	}
	else
		wait(&status);

	return (0);
}
