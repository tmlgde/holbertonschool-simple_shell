#include <stdio.h>
#include <unistd.h>

/**
 * main - Programm that prints all the arguments
 *
 * Return: 
 */
int main(int ac, char **av)
{
    (void)ac;

    while (*av)
    {
	    printf("%s\n", *av);
	    av++;
    }

    return (0);
}
