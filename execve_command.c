#include "main.h"

/**
 * execve_command - Fonction that executes a command using
 * execve in a child process.
 * @command_path: the full path to the command to execute.
 * @argv: the arguments to pass to the command (includind
 * the command itself as argv[0])
 * @environ: the environnement variables to pass to the
 * execve function.
 *
 * Return: nothing
 */

int execve_command(char *command_path, char **argv, char **environ)
{
	pid_t child_pid;
	int status;

	if (access(command_path, X_OK) != 0)
	{
		perror("command not found or not executable");
		return (-1);
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error fork:");
	}

	if (child_pid == 0)
	{
		if (execve(command_path, argv, environ) == -1)
		{
			perror("Error exercve:");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);

	return (0);
}
