#include<stdio.h>
#include<unistd.h>
int main()
{
 fork();
 printf("PID = %d\n",getpid());
 printf("PPID = %d\n",getppid());
 return 0;
}
