#include<stdio.h>
#include<string.h>
struct process
{
 int id,at,bt,ct,tat,wt;
};
int calculate(struct process p[], int n)
{
 int it;
 p[0].ct = p[0].at + p[0].bt;
 for(int i=1;i<n;i++)
 {
 if(p[i].at > p[i-1].ct)
 {
 p[i].ct = p[i].at + p[i].bt;
 it = it + (p[i].at - p[i-1].ct);
 }
 else
 {
 p[i].ct = p[i-1].ct + p[i].bt;
 }
 }
 for(int i=0;i<n;i++)
 {
 p[i].tat = p[i].ct - p[i].at;
 p[i].wt = p[i].tat - p[i].bt;
 }
 return it;
}
void print(struct process p[],int n)
{
 printf("Process Arrival Time Burst Time Completion Time Turn Around Time 
Waiting Time\n");
 for(int i=0;i<n;i++){
 printf(" 
%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
 }
}
int main()
{
 int n;
 double atat=0.0,awt=0.0;
 printf("Enter the Number of Processes: ");
 scanf("%d",&n);
 struct process p[n];
 for(int i=0;i<n;i++){
 p[i].id = i+1;
 printf("Enter the Arrival and Burst Time of Process %d: ",i+1);
 scanf("%d %d",&p[i].at,&p[i].bt);
 }
 int it = calculate(p,n);
 print(p,n);
 for(int i=0;i<n;i++)
 {
 atat+=p[i].tat;
 awt+=p[i].wt;
 }
 atat=atat/(double)n;
 awt=awt/(double)n;
 printf("Average TAT: %lf\n",atat);
 printf("Average WT: %lf\n",awt);
 printf("Throughput: %lf\n",(double)n/p[n-1].ct);
 printf("CPU Utilization: %lf %%\n",((p[n-1].ct-it)/(double)p[n-1].ct)*100);
 printf("CPU Idlency: %lf %%",(it/(double)p[n-1].ct)*100);
 return 0;
}
