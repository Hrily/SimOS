#include <stdio.h>
#include <stdlib.h>

struct process								//Structure of a process
{
	int pt;									//Process Number
	int at;									//Arrival Time
	int bt;									//Burst Time
	int wt;									//Waiting Time
	int tt;									//Turn Around Time
	int rt;									//Remaining Time
	int ct;									//Completion Time
	int completed;							//Completed or not
	int prior;								//Priority of process
}pro;


int n;										//Number of processes
int q[100];									//Queue  
int front=-1,rear=-1;						//Front and rear of queue

void enqueue(int i)							//Function to enqueue process in queue
{
	if(rear==100)
	printf("overflow");
	rear++;
	q[rear]=i;
	if(front==-1)
	front=0;
}

int dequeue()								//Function to dequeue process from queue
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

int isInQueue(int i)						//Function to check if process is in queue
{
	int k;
	for(k=front;k<=rear;k++)
	{
		if(q[k]==i)
			return 1;
	}
	return 0;

}

void sortByArrival(struct process *p)		//Sorting by arrival time
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
	int i,j,time=0;
	int sum_bt=0;				//Total burst time
	int tq;						//Time Quantun
	struct process *p;
	
    float avgwt=0;				//Average Waiting Time
    float atat = 0;				//Average TurnAround Time
	
	scanf("%d%d",&n,&tq);		//Enter total Number of processes
	p = malloc(n*sizeof(pro));
	for(i=0;i<n;i++)			//Enter the details of project
	{
		scanf("%d%d%d%d",&p[i].pt,&p[i].at,&p[i].bt,&p[i].prior);
		p[i].rt=p[i].bt;		//Remaining Time of process
		p[i].completed=0;
		sum_bt+=p[i].bt;

	}

	sortByArrival(p);
	enqueue(0);        
							
	for(time=p[0].at;time<sum_bt;)      
	{   i=dequeue();
		if(p[i].rt<=tq)
		{                         
              time+=p[i].rt;          
			p[i].rt=0;
			p[i].completed=1;          
			
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
	

	for(i=0;i<n;i++)
	{
		atat+=p[i].tt;
		avgwt+=p[i].wt;
		printf("\n\n");
		printf("%d\t%d\t%d\t%d\n",p[i].pt,p[i].ct,p[i].tt,p[i].wt);		//Process name,Completion Time,TurnAround Time,Waiting Time
	}
	printf("\nAverage TT:%f\n",atat/n);				//Average Turn Around Time
	printf("Average WT:%f\n",avgwt/n);				//Average Waiting time
	
	return 0;
}