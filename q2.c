#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    int i;
    pid_t p = fork();
    if(p<0)
    {
        printf("Fork Failed : ");
        exit(1);
    }
    if(p==0)
    {
        printf("\nInside Child ");
        printf("\nChild PID is = %d",getpid());
        printf("\nEven Number is : ");
        for(i=1; i<100; i++)
        {
            if(i%2==0)
                printf("%d ",i);
        }
    }
    else
        sleep(3);
    if(p>0)
    {
        printf("\nParent Child ");
        printf("\nParent PID is = %d",getpid());
        printf("\nOdd Number is : ");
        for(i=1; i<100; i++)
        {
            if(i%2==1)
                printf("%d ",i);
        }
    }
    return 0;
}
