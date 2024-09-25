#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t p, pc;
    printf("before fork\n");
    p = fork();
    if (p == 0) // child
    {
        printf("I am child having id %d\n", getpid());
        printf("My parent's id is %d\n", getppid());
        pc = fork();
        if (pc == 0) // child
        {
            printf("I am child of the child  %d\n", getpid());
            printf("My parent's id is %d\n", getppid());
        } else {
            wait(NULL);
            printf("My child's id is %d\n", pc);
            printf("I am child/parent having id %d\n", getpid());
        }
    } else // parent
    {
        wait(NULL);
        printf("My child's id is %d\n", p);
        printf("I am parent having id %d\n", getpid());
    }
    printf("Common area of code  \n");
}