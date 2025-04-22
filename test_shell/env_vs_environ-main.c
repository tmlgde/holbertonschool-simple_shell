#include <stdio.h>
#include <string.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("L'adresse de env est : %p\n", (void *)&env);
	printf("L'adresse de environ est : %p\n", (void *)&environ);

	return (0);
}
