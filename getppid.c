#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Mon PID : %d\n", getpid());
    printf("PID de mon parent (PPID) : %d\n", getppid());
    return 0;
}

