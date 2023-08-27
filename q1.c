#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    pid_t p;
    p=fork();
    if(p<0)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    if(p==0)
    {
        printf("\nPID of child process %d ",getpid());
        printf("\nChild p = %d",p);
    }
    else if(p>0)
    {
        printf("\nPID of parent process %d ",getpid());
        printf("\nparent p = %d",p);
    }
    return 0;
}
