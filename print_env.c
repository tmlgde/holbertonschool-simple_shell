#include "main.h"

void print_env(void)
{
	int i = 0;

	while (environ != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
