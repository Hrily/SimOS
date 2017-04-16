#include<stdio.h>

struct process
{
        int at,bt,pri,id;
}X[1005];

int done[1005],id[1005],front[4],rear[4],Q[4][1000],Bt[1005],queued[1005],ct[1005],wt[1005],tat[1005];

int t;
int cnt;

void push(int ind,int p)
{
        queued[p]=1;
        Q[ind][rear[ind]]=p;
        rear[ind]++;
}

int pop(int ind)
{
        int x=Q[ind][front[ind]];
        front[ind]++;
        queued[x]=0;
        return x;
}

int get(int priority)
{
        if(priority==1)
        return 1;

        if(priority==2)
        return 2;

        return 3;
}

int ok(int ind)
{
        if(front[ind]<rear[ind])
        return 1;

        return 0;
}

int doround(int ind,int time)
{
        int p=pop(ind);
        if(Bt[p]<=t)
        {
                done[p]=1;
                ct[p]=time+Bt[p];
                cnt++;
                return Bt[p];
        }

        else
        {
                Bt[p]-=t;
                push(ind,p);
                return t;
        }
}


int main()
{
//        printf("Enter No. of Processes\n");

        int N;
        scanf("%d%d",&N,&t);

        int i;

        for (i=1;i<=N;i++)
        {
                scanf("%d%d%d%d",&X[i].id,&X[i].at,&X[i].bt,&X[i].pri);
                Bt[i]=X[i].bt;
        }

        for (i=1;i<=N;i++)
        id[i]=get(X[i].pri);

        int time=0;
        for (i=1;i<=N;i++)
        {
                if(X[i].at<=time)
                {
                        push(id[i],i);
                }
    }


        while(cnt<N)
        {
                int st=time;
                if(ok(1))
                {
                        int x=doround(1,time);
                        time+=x;

                        for (i=1;i<=N;i++)
                        {
                                if(!done[i] && queued[i]==0 && X[i].at<=time)
                                push(id[i],i);
                        }

                        continue;
                }

                if(ok(2))
                {
                        int x=doround(2,time);
                        time+=x;

                        for (i=1;i<=N;i++)
                        {
                                if(!done[i] && queued[i]==0 && X[i].at<=time)
                                push(id[i],i);
                        }

                        continue;
                }

                if(ok(3))
                {
                        int p=pop(3);
                        time+=Bt[p];
                        done[p]=1;
                        cnt++;
                        ct[p]=time;
                        for (i=1;i<=N;i++)
                        {
                                if(!done[i] && queued[i]==0 && X[i].at<=time)
                                push(id[i],i);
                        }

                        continue;
                }

                 time++;
                        for (i=1;i<=N;i++)
                        {
                                if(!done[i] && queued[i]==0 && X[i].at<=time)
       push(id[i],i);
                        }

                        continue;
        }
	
	float tats=0,wts=0;

        for (i=1;i<=N;i++)
        {
                tat[i]=ct[i]-X[i].at;
                wt[i]=tat[i]-X[i].bt;
        	tats+=tat[i];
		wts+=wt[i];
	}
	
 //       printf("ct\twt\ttat\n");
        for (i=1;i<=N;i++)
        {
                printf("%d %d %d %d\n",X[i].id,ct[i],tat[i],wt[i]);
        }
	tats=tats/N;
	wts=wts/N;
	
	printf("Average TT: %f\n",tats);
	printf("Average WT: %f",wts);
}
