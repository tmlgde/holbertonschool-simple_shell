#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    char *val = _getenv("PATH");

    if (val)
    {
        printf("PATH = %s\n", val);
        free(val);
    }
    else
        printf("PATH non trouvé\n");

    return 0;
}
