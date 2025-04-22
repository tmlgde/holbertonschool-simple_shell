#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Programm that executes the command
 * ls -l / tmp in 5 child processes.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	pid_t child_pid;
	int status;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			sleep(3);
			execve(argv[0], argv, NULL);
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
			printf("(%d) %d : Finish, i am the parent\n", getppid(), child_pid);
		}
	}
	return (0);
}
