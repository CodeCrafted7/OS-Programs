#include<stdio.h>
#include<unistd.h>
int main()
{
 int n,odd=0,even=0;
 printf("Enter the size of the Array:");
 scanf("%d",&n);
 int A[n];
 printf("Enter Elements:");
 for(int i=0;i<n;i++)
 scanf("%d",&A[i]);
 int x = fork();
 for(int i=0;i<n;i++){
 if(x==0){
 if(A[i]%2==0){
 even+=A[i];
 printf("%d ",getpid()); }
 else{
 odd+=A[i];
 printf("%d ",getpid()); }
 }
 else{
 if(A[i]%2==0){
 even+=A[i];
 printf("%d ",getpid()); }
 else{
 odd+=A[i];
 printf("%d ",getpid()); }
 }
 }
 printf("\nSum of Even Numbers: %d\n",even);
 printf("Sum of Odd Numbers: %d\n",odd);
 return 0; }
