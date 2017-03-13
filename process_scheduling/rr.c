#include <stdio.h>
#include <stdlib.h>

struct process												//Structure of a process
{
	int name;												//Name of the process
	int at,bt,wt,tt,rt,ct;									//Arrival time, Burst Time, Waiting Time, TurnAround Time, Remaining Time, Completion time
	int completed;											//Completed
	
}pro;


int n;
int q[10];  
int front=-1,rear=-1;

void enqueue(int i)											//Function to enqueue process in queue
{
	if(rear==10)
	printf("overflow");
	rear++;
	q[rear]=i;
	if(front==-1)
	front=0;
}

int dequeue()												//Function to dequeue process from queue
{
	if(front==-1)
	printf("underflow");
	int temp=q[front];
	if(front==rear)
		front=rear=-1;
	else
		front++;
	return temp;
}

int isInQueue(int i)										//Function to check if process is in queue
{
	int k;
	for(k=front;k<=rear;k++)
	{
		if(q[k]==i)
			return 1;
	}
	return 0;

}

void sortByArrival(struct process *p)						//Sorting by arrival
{
	struct process temp;
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
}

int main()
{
	int i,j,time=0,sum_bt=0,tq;
	int c;
	struct process *p;
	
        float avgwt=0;
	printf("Enter no of processes:");
	scanf("%d",&n);
	p = malloc(n*sizeof(pro));
	for(i=0,c=1;i<n;i++,c++)									//Enter the details of project
	{
		p[i].name=c;
		printf("\nEnter the arrival time and burst time of process %d: ",p[i].name);
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].rt=p[i].bt;
		p[i].completed=0;
		sum_bt+=p[i].bt;
 
	}

	printf("\nEnter the time quantum:");					
	scanf("%d",&tq);

	sortByArrival(p);
	enqueue(0);        
	printf("Process execution order: ");						
	for(time=p[0].at;time<sum_bt;)      
	{   i=dequeue();
		if(p[i].rt<=tq)
		{                         
              time+=p[i].rt;          
			p[i].rt=0;
			p[i].completed=1;          
			printf(" %d ",p[i].name);
			time+=p[i].rt;
			p[i].wt=time-p[i].at-p[i].bt;
			p[i].tt=time-p[i].at;  
			p[i].ct = time;     
			
			for(j=0;j<n;j++)              
			{
		            if(p[j].at<=time && p[j].completed!=1&& isInQueue(j)!=1)
		            {
			            enqueue(j);
				}
		           }
	        }
		else             
		{
			time+=tq;
			p[i].rt-=tq;
			printf(" %d ",p[i].name);
			for(j=0;j<n;j++)
			{
		            if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1)
		             {
			            enqueue(j);          
			            }
          		 }
           		enqueue(i);   
           
    		}

    
    
	}
	float atat = 0;
	printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\t Waiting Time\tTurnAround Time\n");
	for(i=0;i<n;i++)
	{
		atat+=p[i].tt;
		avgwt+=p[i].wt;
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tt);
	}
	printf("\nAverage waiting time:%f\n",avgwt/n);
	printf("Average turn around time:%f\n",atat/n);
	
	return 0;
}