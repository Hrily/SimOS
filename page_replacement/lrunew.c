#include<stdio.h>
#include<stdlib.h>
int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;
    for(i=1;i<n;++i){
        if(time[i]<minimum)
        {
            minimum=time[i];
            pos=i;
        }
    }
    return pos;
}
int main()
{
    int fr,p,frames[10],pages[30],count=0,time[10],f1,f2,i,j,pos,faults=0;
    float fra,hr;
    printf("Enter number of frames: ");
    scanf("%d",&fr);
    printf("Enter number of pages: ");
    scanf("%d",&p);
    printf("Enter reference string: ");
    for(i= 0;i<p;++i)
    {
        scanf("%d",&pages[i]);
    }
        for(i = 0; i <fr; ++i)
        {
        frames[i]=-1;
    }
    for(i=0;i<p; ++i)
    {
        f1=f2=0;
        for(j = 0; j<fr;++j)
        {
            if(frames[j]==pages[i])
            {
                count++;
                time[j]=count;
                   f1=f2=1;
                   break;
            }
        }
        if(f1==0)
        {
            for(j = 0;j<fr; ++j)
            {
                if(frames[j]==-1)
                {
                    count++;
                    faults++;
                    frames[j]=pages[i];
                    time[j]=count;
                    f2=1;
                    break;
                }
            }
        }
        if(f2==0)
        {
            pos=findLRU(time,fr);
            count++;
            faults++;
            frames[pos]=pages[i];
            time[pos]=count;
        }
        printf("\n");
        for(j=0;j<fr;++j)
        {
            printf("%d\t",frames[j]);
        }
        
        printf("\n\n\t\t%f\t\n\n",(faults*1.0)/((i+1)*1.0));
    }
    fra=(float)faults/p;
        hr=1-fra;
        printf("\nPage fault is %d\n",faults);
        printf("%f\n",hr);
        printf("Fault ratio is %f\n",fra);
    return 0;
}
