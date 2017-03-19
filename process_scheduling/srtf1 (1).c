//Rashika Verma
//15CO238

#include <stdio.h>
#include <stdlib.h>

struct process
{
	int name;			
	int at,bt,rt,tt,wt,ct;				
}p;					

int main()
{
	int endTime,i,c,smallest;
	int remain=0,n,time,sum_wait=0,sum_turnaround=0;
	printf("Enter no of Processes : ");					
	scanf("%d",&n);
	
	struct process *pro;
	pro = malloc( n * sizeof(p) );												
	int sum_bt = 0;										//Total burst time

	for(i=0,c = 1;i<n;i++)								//Enter arrival time and burst time of process
	{
		pro[i].name = c;								
		printf("Enter arrival time for Process P%d : ",pro[i].name);
		scanf("%d",&pro[i].at);
		printf("Enter burst time for Process P%d : ",pro[i].name);
		scanf("%d",&pro[i].bt);
		pro[i].rt=pro[i].bt;
		sum_bt+=pro[i].bt;
		c++;
	}
	int processGantt[sum_bt];

	printf("\n\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\t Completion time\n\n");
	pro[1000].rt=9999;
	
	for(time=0;remain!=n;time++)					//To calculate waiting time, completion time and turnaround time of process
	{
		smallest=1000;
		for(i=0;i<n;i++)
		{
			if(pro[i].at<=time && pro[i].rt<pro[smallest].rt&& pro[i].rt>0)
			{
				processGantt[time]=i;
				smallest=i;
			}
		}
		pro[smallest].rt--;
		if(pro[smallest].rt==0)
		{
			remain++;
			endTime=time+1;
			pro[smallest].tt = endTime-pro[smallest].at;				//TurnAround Time of each process
			pro[smallest].wt = endTime-pro[smallest].bt-pro[smallest].at; //Waiting time of each process
			pro[smallest].ct = endTime;									//Completion time of each process
			printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t",smallest+1,pro[smallest].at,pro[smallest].bt,pro[smallest].tt,pro[smallest].wt,endTime);
			sum_wait+=pro[smallest].wt;
			sum_turnaround+=pro[smallest].tt;
		}
	}

	printf("\n\nAverage waiting time = %f\n",sum_wait*1.0/n);			//Total waiting time
	printf("Average Turnaround time = %f\n\n",sum_turnaround*1.0/5);	//Total turnaround time
	for(i=0;i<time;i++)													//To print Gantt Chart 
	{
		printf("%d->P%d ",i,processGantt[i]+1);
	}
	printf("%d",time);
printf("\n");
}


