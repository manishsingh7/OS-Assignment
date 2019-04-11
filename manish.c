1.Write a program in C which reads input CPU bursts from a the first line of a text file named as CPU_BURST.txt. Validate the input numbers whether the numbers are positive intergers or not. Consider the numbers as CPU burst.If there are 5 positive integers in the first line of the text file then the program treat those argument as required CPU bust for P1, P2, P3, P4, and P5 process and calculate average waiting time and average turn around time. Consider used scheduling algorithm as SJF and same arrival time for all the processes.

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  int main()
{

  FILE *fp = fopen("cpu_burst.txt", "r");
  int bt[20],p[20],wt[20],tat[20],i=0,j,n=5,total=0,pos,temp;
  float avg_wt,avg_tat;
  printf("\nReading  CPU_BURST.txt  File\n");
  
   while((getc(fp))!=EOF)
     {

         fscanf(fp, "%d", &bt[i]);
           if(bt[i]>0){
         p[i]=i+1;  i++;}          
}
n=i;
for(i=0;i<n;i++)

{
    pos=i;
    for(j=i+1;j<n;j++)
    {
        if(bt[j]<bt[pos])
            pos=j;
    }
    
    temp=bt[i];
    bt[i]=bt[pos];
    bt[pos]=temp;
    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;
}
wt[0]=0;            

for(i=1;i<n;i++)
{
    wt[i]=0;
    for(j=0;j<i;j++)
        wt[i]+=bt[j];
    total+=wt[i];
}
avg_wt=(float)total/n;     
total=0;
printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
   for(i=0;i<n;i++)
   {
       tat[i]=bt[i]+wt[i];     
       total+=tat[i];
       printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
   }
   avg_tat=(float)total/n;     
   printf("\n\nAverage Waiting  Time=%f",avg_wt);
   printf("\nAverage  Turnaround  Time=%f\n",avg_tat);
   fclose(fp);
   return 0;
}




A uniprocessor system has n number of CPU intensive processes, each process has its own requirement of CPU burst.The process with lowest CPU 
burst is given the highest priority. A late arriving higher priority process can preempt a currently running process with lower priority.Simulate a scheduler
 that is scheduling the processes in such a way that higher priority process is never starved due to the execution of lower priority process. What should be its
 average waiting time and average turnaround time if no two processes are arriving at same time

#include<stdio.h>
int n;
struct process
{

int p_no;

int arrival_t,burst_t,ct,wait_t,taround_time,p;

int flag;
 }p_list[100];
 void Sorting()
 {
struct process p;

int i, j;

for(i=0;i<n-1;i++)

{

for(j=i+1;j<n;j++)

{

if(p_list[i].arrival_t > p_list[j].arrival_t)

{

p = p_list[i];

p_list[i] = p_list[j];

p_list[j] = p;

}

}

}
 }
 int main()
 {

int i,t=0,b_t=0,peak;

int a[10];

float wait_time = 0, taround_time = 0, avg_w_t=0, avg_taround_time=0;

printf("enter the no. of processes: ");

scanf("%d",&n);

for(i = 0; i < n; i++)

{

p_list[i].p_no = i+1;

printf("\nEnter Detail For P%d process:-\n", p_list[i].p_no);
printf("Enter Arrival Time: ");
scanf("%d", &p_list[i].arrival_t );
printf("Enter Burst Time: ");
scanf("%d", &p_list[i].burst_t);
p_list[i].flag = 0;
b_t = b_t + p_list[i].burst_t;
}
Sorting();
for(i=0;i<n;i++)
{
a[i]=p_list[i].burst_t;
}
p_list[9].burst_t = 9999;
for(t = p_list[0].arrival_t; t <= b_t+1;)
{
peak = 9;
for(i=0;i<n;i++)
{
if(p_list[i].arrival_t <= t && p_list[i].burst_t < p_list[peak].burst_t && p_list[i].flag != 1)
{
peak = i;
}
if(p_list[peak].burst_t==0 && p_list[i].flag != 1)
{
p_list[i].flag = 1;
p_list[peak].ct=t;p_list[peak].burst_t=9999;
printf("P%d completes in %d\n",p_list[i].p_no,p_list[peak].ct);
}
}
t++;
(p_list[peak].burst_t)--;
}
for(i=0;i<n;i++)
{
p_list[i].taround_time=(p_list[i].ct)-(p_list[i].arrival_t);
avg_taround_time=avg_taround_time+p_list[i].taround_time;
p_list[i].wait_t=((p_list[i].taround_time)-a[i]);
avg_w_t=avg_w_t+p_list[i].wait_t;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",p_list[i].p_no,p_list[i].arrival_t,p_list[i].ct,p_list[i].taround_time
,p_list[i].wait_t);
 }
printf("Average Turn around Time: %f\t\n\n",avg_taround_time);
printf("Average Waiting Time :\t %f\t\n",avg_w_t);
}
