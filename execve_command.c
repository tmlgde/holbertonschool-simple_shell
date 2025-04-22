#include "main.h"

/**
 * execve_command - Fonction that executes a command in a
 * child process using execve.
 * @command_path: the full path to the command to execute.
 * @argv: the arguments to pass to the command (includind
 * the command itself as argv[0])
 * @environ: the environnement variables to pass to the
 * child process.
 *
 * Return: 0 on success, or -1 if the command is not executable
 * of fork fails.
 */

int execve_command(char *command_path, char **argv, char **environ)
{
	pid_t child_pid;
	int status;

	/*Check if the command is accessible and executable*/
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
		/*Replace the child process with the new programm*/
		if (execve(command_path, argv, environ) == -1)
		{
			perror("Error exercve:");
			return (1);
		}
	}
	else
		wait(&status);

	return (0);
}
