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

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error fork:");
	}
	if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror("Error exercve:");
		}
	}
	else
		wait(&status);

	return (0);
}
