//RAJESWARI DHIR
//15CO255

#include<stdio.h>
#include<stdlib.h>

struct process
  {
    int at,bt,pt,rt,ct,inq,p,st,tat,wt;
    };
void sorta(struct process *m,int n)
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
	 
  int main()
    {
	    int n,time=0,tot=0,i,tq,t,pr=-1,Q,a=0,b=0,min=999,k=-1;
	    float awt=0,atat=0;
      struct process *m,*ba;
      // printf("enter no of processes\n");
      scanf("%d",&n);
      m=(struct process *)malloc(n*sizeof(struct process));
     // q=(int *)malloc(n*sizeof(int));
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
	  m[i].st=0;
	  }
        sorta(m,n);
        tot+=m[0].at;
        time=m[0].at;
        
        while(time<tot)
           {
                for(i=0;i<n;i++)
                     {
                       if(m[i].at<=time && m[i].bt<min && m[i].st==0)
                          {
                            min=m[i].bt;
                            k=i;
                          }
                      }
                            
        if(min!=999)
           {
              m[k].rt=0;
                  // printf("time %d ",time);
                   time+=m[k].bt;
                   m[k].ct=time;
                      m[k].tat=m[k].ct-m[k].at;
                      m[k].wt=m[k].tat-m[k].bt;
                       atat+=m[k].ct-m[k].at;
                       awt+=m[k].ct-m[k].at-m[k].bt;
                       min=999;
                       m[k].st=1;
                       k=-1;
             }
            else
               {
                 time++;
                 tot++;
                 }
               }
            for(i=0;i<n;i++)
           {
              printf("%d %d %d %d\n",m[i].pt+1,m[i].ct,m[i].tat,m[i].wt);              // To print the completion time
              }
           printf("Average TT: %f\nAverage WT: %f\n",atat/n,awt/n);   
           }                 
