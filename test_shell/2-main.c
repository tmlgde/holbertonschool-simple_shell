#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(void)
{
        char str[] = "Split the line in tokens";
        char **token = split_line(str, " ");
        size_t i;

        for (i = 0; token[i] != NULL; i++)
        {
                printf("%s\n", token[i]);
                free(token[i]);
        }

        free(token);
        return (0);
}
