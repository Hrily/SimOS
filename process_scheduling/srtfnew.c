//Rashika Verma
//15CO238

#include <stdio.h>
#include <stdlib.h>

struct process
{
	int pt;								//Processs Number
	int at;								//Arrival Time
	int bt;								//Burst Time
	int rt;								//Remaining Time
	int tt;								//TurnAround Time
	int wt;								//Waiting Time
	int ct;								//Completion Time
	int prior;							//Priority of process
	int inq;							//Is in queue or not
}p;					

int main()
{
	int endTime,i,smallest,tq;
	int remain=0,n,time,sum_wait=0,sum_turnaround=0;
					
	scanf("%d%d",&n,&tq);
	
	struct process *pro;
	pro = malloc( n * sizeof(p) );												
	int sum_bt = 0;										//Total burst time

	for(i=0;i<n;i++)								//Enter arrival time and burst time of process
	{	
		scanf("%d%d%d%d",&pro[i].pt,&pro[i].at,&pro[i].bt,&pro[i].prior);
		pro[i].rt=pro[i].bt;
		sum_bt+=pro[i].bt;
	}
	pro[1000].rt=9999;
	
	for(time=0;remain!=n;time++)					//To calculate waiting time, completion time and turnaround time of process
	{
		smallest=1000;
		for(i=0;i<n;i++)
		{
			if(pro[i].at<=time && pro[i].rt<pro[smallest].rt&& pro[i].rt>0)
			{
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
			printf("\n%d\t\t%d\t\t%d\t\t%d",smallest+1,endTime,pro[smallest].wt,pro[smallest].tt);
			sum_wait+=pro[smallest].wt;
			sum_turnaround+=pro[smallest].tt;
		}
	}

	printf("\n\nAverage TT = %f\n",sum_turnaround*1.0/n);			//Total waiting time
	printf("Average WT = %f\n\n",sum_wait*1.0/n);	//Total turnaround time
	
printf("\n");
}

