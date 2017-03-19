//Prerana Mahalanobis
//15CO135

#include <stdio.h>
#include <stdlib.h>

struct process                                                  //Structure of a process
{
        int name;
        int at,bt,wt,tat,ct;
}pro;

int main()
{
        int n;
        printf("\nEnter the No. of processes :");
        scanf("%d",&n);
        
        struct process *p;
        p = malloc(n*sizeof(pro)); 
        
        int i,j,count = 0;
        
        for(i=0;i<n;i++)                                       //Name of each process
                p[i].name = (i+1);
        
        int min = 0;
        
        for(i=0;i<n;i++)
        {
                printf("\tEnter the arrival and burst time of %d process :",i+1);              //Arrival and burst timeof each process
                scanf(" %d%d",&p[i].at,&p[i].bt);
              
                if(min > p[i].at)                                                             //To find process with shortest arrival time
                        min = p[i].at;
         }
         
         for(i=0;i<n;i++)                                                                     //Number of processes with same shortest arrival time
         {
                 if(p[i].at == min)
                        count++;
         }
         
        int b[count];
        
        for(i=0;i<count;i++)                                                                
        {
                if(p[i].at == min)
                {
                        b[i] = i;
                }
        }
        
        int temp;
        
        for(i=0;i<count;i++)                                                         //Sorting according to shortest arrival as well as shortest burst time
        {
                for(j=0;j<count;j++)
                {
                        if(p[b[i]].bt < p[b[j]].bt)
                        {
                                temp=p[j].name;
                                p[j].name=p[i].name;
                                p[i].name=temp;

                                temp=p[j].at;
                                p[j].at=p[i].at;
                                p[i].at=temp;

                                temp=p[j].bt;
                                p[j].bt=p[i].bt;
                                p[i].bt=temp;
                        }         
                }
                
        }
        
        p[0].ct = p[0].at+p[0].bt;                      //To calculate completion, turn around and waiting time of process with shortest arrival and shortest burst time                
        p[0].tat = p[0].ct - p[0].at;
        p[0].wt = p[0].tat-p[0].bt;
        
        for(i=1;i<n;i++)                                    //Sorting rest of processes according to burst time
        {
                for(j=1;j<n;j++)
                {
                        if(p[i].bt<p[j].bt)
                        {
                                temp=p[j].name;
                                p[j].name=p[i].name;
                                p[i].name=temp;

                                temp=p[j].at;
                                p[j].at=p[i].at;
                                p[i].at=temp;

                                temp=p[j].bt;
                                p[j].bt=p[i].bt;
                                p[i].bt=temp;
                        }
                }
        }

        for(i = 1;i<n;i++)                              //Calculating completion, waiting and turn around time of processes
        {
                p[i].ct = p[i-1].ct+p[i].bt;
                p[i].tat = p[i].ct-p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
               
         }

                        
        printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnAround Time\tWaiting Time\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        }
        float atat=0,awt=0;
        for(i=0;i<n;i++)
        {
                atat+=p[i].tat;
                awt+=p[i].wt;
        }

        printf("Average turn around time:%f\n",atat/n);
        printf("Average waiting time:%f\n",awt/n);


return 0;
}
