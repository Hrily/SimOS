//RAJESWARI DHIR
//15CO255
#include<stdio.h>
#include<stdlib.h>

int f=-1,r=-1;
int *q;
void enqueue( int n,int ele)               // function to enqueue processes into a queue waiting for cpu execution
  {
    if(f==-1 && r==-1)
      {
       f++;
       r++;
       q[r]=ele;
       }
     else {
            r=(r+1)%n;
	    q[r]=ele;
	    }
  }

int dequeue(int n)                      // function t dequeue a process from a queue after their time slot expires 
  {
    int x=q[f];
    if(f==r)
      { 
        f=-1;
	r=-1;
	}
    else f=(f+1)%n;
   return x;
    }
struct process                         // the structure of a process
  {
    int at,bt,pt,rt,ct,inq,p,tat,wt;
    };
void sorta(struct process *m,int n)    // Function to sort the processes in ascending order of arrival time
  {
    int i,j,k,min;

    struct process temp;
    for(i=0;i<n-1;i++)
      {
        min=m[i].at;
	k=i;
	for(j=i+1;j<n;j++)
	  {
	    if(m[j].at<min)
	      {
	        min=m[j].at;
		k=j;
	      }
	   }
	if(k!=i)
	{
	  temp=m[k];
	  m[k]=m[i];
	  m[i]=temp;
	  }
  }
  }

  void main()
    {
	    int n,time=0,tot=0,i,tq,t,pr=-1,Q;
	    float awt=0,atat=0;
      struct process *m,*ba;
      // printf("enter no of processes\n");
      scanf("%d",&n);
      m=(struct process *)malloc(n*sizeof(struct process));
      q=(int *)malloc(n*sizeof(int));
      // printf("enter time quantum\n");
      scanf("%d",&Q); 
      for(i=0;i<n;i++)                                 // To enter the process details
        {
//	  printf("enter process no \n");
	  scanf("%d",&m[i].pt);
//	  printf("enter arrival time\n");
	  scanf("%d",&m[i].at);
//	  printf("enter burst time\n");
	  scanf("%d",&m[i].bt);
//	  printf("enter priority\n");
	  scanf("%d",&m[i].p);
	  m[i].pt=i;
	  m[i].rt=m[i].bt;
          tot+=m[i].bt;
	  m[i].inq=0;
	  }
        sorta(m,n);
        tot+=m[0].at;
        enqueue(n,0);
        for(time=m[0].at;time<tot;)
           { 
                for(i=0;i<n;i++)
                   {
                     if(m[i].at<=time&& m[i].p>pr && m[i].rt!=0)
                        {
                           pr=m[i].p;
                           tq=i; 
                          }
                      }
                      
                   m[tq].rt=0;
                  // printf("time %d ",time);
                   time+=m[tq].bt;
                  // printf("after adding %d it is %d\n",m[tq].bt,time);
                   if(m[tq].rt==0)
                     {m[tq].ct=time;
                      m[tq].tat=m[tq].ct-m[tq].at;
                      m[tq].wt=m[tq].tat-m[tq].bt;
                       atat+=m[tq].ct-m[tq].at;
                       awt+=m[tq].ct-m[tq].at-m[tq].bt;
                       }
                    // printf("Ctime %d \n",m[tq].ct);
                  pr=-1;
                  }
        // printf("pno\tct\ttt\twt\n");
         for(i=0;i<n;i++)
           {
              printf("%d %d %d %d\n",m[i].pt+1,m[i].ct,m[i].tat,m[i].wt);              // To print the completion time
              }
           printf("Average TT: %f\nAverage WT: %f\n",atat/n,awt/n);   
           }                    
