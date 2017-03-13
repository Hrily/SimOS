#include<stdio.h>
#include<stdlib.h>
int main()
{
        int n;
        printf("\nEnter the number of processes : ");
        scanf("%d",&n);

        int at[n],bt[n],wt[n],tat[n],ct[n],p[n];
        int i,j;
        for(i=0;i<n;i++)
                p[i] = (i+1);

        for(i=0;i<n;i++)
        {
                printf("Enter the arrival and burst time of process[%d] :",i+1);
                scanf(" %d%d",&at[i],&bt[i]);

        }
        int temp;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        if(at[i]<at[j])
                        {
                                temp=p[j];
                                p[j]=p[i];
                                p[i]=temp;

                                temp=at[j];
                                at[j]=at[i];
                                at[i]=temp;

                                temp=bt[j];
				 bt[j]=bt[i];
                                bt[i]=temp;
                        }
                }
        }
        ct[0] = at[0]+bt[0];
        tat[0] = ct[0] - at[0];
        wt[0] = tat[0]-bt[0];
        for(i=1;i<n;i++)
        {
                for(j=1;j<n;j++)
                {
                        if(bt[i]<bt[j])
                        {
                                temp=p[j];
                                p[j]=p[i];
                                p[i]=temp;

                                temp=at[j];
                                at[j]=at[i];
                                at[i]=temp;

                                temp=bt[j];
                                bt[j]=bt[i];
                                bt[i]=temp;
                        }
                }
        }
        for(i = 1;i<n;i++)
        {
                ct[i] = ct[i-1]+bt[i];
                tat[i] = ct[i]-at[i];
                wt[i] = tat[i]-bt[i];
	}
        printf("process\t\tArrival Time\tBurst Time   Completion time\tTurnaround time\t\tWaiting time\n");
        for(i=0;i<n;i++)
        {
        	printf("Process[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        }
        float atat=0,awt=0;
        for(i=0;i<n;i++)
        {
                atat+=tat[i];
                awt+=wt[i];
        }

        printf("average tat: %f\n",atat/n);
        printf("average wt: %f\n",awt/n);
	return 0;
}
