#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
 int x;
 printf("Press 0 for Orphan or 1 for Zombie:");
 scanf("%d",&x);
 pid_t id = fork();
 if(x == 1){
 if(id == 0){
 printf("%d\n",getpid());
 printf("Child\n");
 }
 else{
 sleep(2);
 printf("%d\n",getpid());
 printf("Parent\n");
 }
 return 0;
 }
 else if(x == 0){
 if(id == 0){
 sleep(2);
 printf("%d\n",getpid());
 printf("Child\n");
 }
 else{
 printf("%d\n",getpid());
 printf("Parent\n");
 }
 return 0;
 }
}
